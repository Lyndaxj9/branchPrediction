#include "gshare.h"
#include <iostream>
#include <sstream>
#include <math.h>

//CONSTRUCTOR
Gshare::Gshare(std::vector<std::string> addrIN, std::vector<int> actualIN) {
    address = addrIN;
    actual = actualIN;
    numBranches = address.size();
    predictTable.resize(tableSize, 3);
    numCorrect = 0;
}

int Gshare::predict(int historyLengthIN) {
    int tableMod;
    std::stringstream ss;
    unsigned int checkChar;
    std::string index;
    unsigned int x;
    
    //initTable(tableSizeIN);

    for (int i = 0; i < numBranches; i++) {
        index = (address[i]).substr(2,9);
        ss.clear();
        ss << std::hex << index;
        ss >> x;
        ghr = ghr & (int)(pow(2, historyLengthIN)-1);
        checkChar = static_cast<int>(x);
        tableMod = ghr & checkChar;
        std::cout << "ghr: " << ghr << "checkChar: " << checkChar << "tableMod: " << tableMod << std::endl;
        /*
        tableMod = checkChar % tableSizeIN; 
        checkPredict(tableMod,i);
        */
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
}

int Gshare::getNumBranches() {
    return numBranches;
}
