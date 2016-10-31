#include "gshare.h"
#include <iostream>
#include <sstream>
#include <math.h>
#include <bitset>

//CONSTRUCTOR
Gshare::Gshare(std::vector<std::string> addrIN, std::vector<int> actualIN) {
    address = addrIN;
    actual = actualIN;
    numBranches = address.size();
}

int Gshare::predict(int historyLengthIN) {
    int tableMod;
    std::stringstream ss;
    int checkChar;
    std::string index;
    unsigned int x;
    
    initTable();

    for (int i = 0; i <numBranches; i++) {
        index = (address[i]).substr(2,9);
        ss.clear();
        ss << std::hex << index;
        ss >> x;
        ghr = ghr & (int)(pow(2, historyLengthIN)-1);
        std::bitset<3> z(ghr);
        //std::cout << "before ghr: " << ghr << " " << z << std::endl;
        checkChar = static_cast<int>(x);
        //checkChar = checkChar & (int)(pow(2, historyLengthIN)-1);
        tableMod = ghr ^ checkChar;
        tableMod = tableMod & (tableSize-1);
        //tableMod = tableMod & (int)(pow(2, historyLengthIN)-1);
        //tableMod = tableMod << 8;
        //std::cout << "ghr: " << ghr << "checkChar: " << checkChar << "tableMod: " << tableMod << std::endl;
        checkPredict(tableMod,i);
        std::bitset<3> y(ghr);
        //std::cout << "after ghr: " << ghr << " " << y << std::endl;
        ss.str("");
    } 
    return numCorrect;
}

void Gshare::checkPredict(int tableModIN, int forIN) {
    if ((predictTable[tableModIN] == 3 || predictTable[tableModIN] == 2) && actual[forIN] == 1) {
        ++numCorrect;
        if(predictTable[tableModIN] == 2) {
            predictTable[tableModIN] = predictTable[tableModIN] + 1;
        }
    } else if ((predictTable[tableModIN] == 1 || predictTable[tableModIN] == 0) && actual[forIN] == 0) {
        ++numCorrect;
        if(predictTable[tableModIN] == 1) {
            predictTable[tableModIN] = predictTable[tableModIN] - 1;
        }
    } else if ((predictTable[tableModIN] == 3 || predictTable[tableModIN] == 2) && actual[forIN] == 0) {
        predictTable[tableModIN] = predictTable[tableModIN] - 1;
    } else if ((predictTable[tableModIN] == 1 || predictTable[tableModIN] == 0) && actual[forIN] == 1) {
        predictTable[tableModIN] = predictTable[tableModIN] + 1;
    }
    //std::cout << "predict table: " << predictTable[tableModIN] << std::endl;
    if (actual[forIN] == 1) {
        ghr = (ghr << 1) | 1;
    } else {
        ghr = ghr << 1;
    }
}

void Gshare::initTable() {
    numCorrect = 0;
    ghr = 0;
    predictTable.clear();
    predictTable.resize(tableSize, 3);
}

int Gshare::getNumBranches() {
    return numBranches;
}
