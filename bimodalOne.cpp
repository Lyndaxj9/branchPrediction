#include "bimodalOne.h"
#include <iostream>
#include <sstream>

//CONSTRUCTOR
BiModalOne::BiModalOne(std::vector<std::string> addrIN, std::vector<int> actualIN) {
    address = addrIN;
    actual = actualIN;
    numBranches = address.size();
    numCorrect = 0;
}

int BiModalOne::predict(int tableSizeIN) {
    int tableMod;
    std::stringstream ss;
    unsigned int checkChar;
    std::string index;
    unsigned int x;
    
    initTable(tableSizeIN);

    for (int i = 0; i < numBranches; i++) {
        index = (address[i]).substr(2,9);
        ss.clear();
        ss << std::hex << index;
        ss >> x;
        checkChar = static_cast<int>(x);
        tableMod = checkChar % tableSizeIN; 
        checkPredict(tableMod,i);
        /*
        index = (address[i]).substr(9);
        ss << index;
        if(!(ss >> checkChar).fail()) {
            tableMod = checkChar % tableSizeIN;
            checkPredict(tableMod, i);
        } else {
            if(index == "a") {
                checkChar = 10;
            } else if(index == "b") {
                checkChar = 11;
            } else if(index == "c") {
                checkChar = 12;
            } else if(index == "d") {
                checkChar = 13;
            } else if(index == "e") {
                checkChar = 14;
            } else if(index == "f") {
                checkChar = 15;
            }
            tableMod = checkChar % tableSizeIN;
            checkPredict(tableMod, i);
        }
        */
        ss.str("");
    } 
    return numCorrect;
}

void BiModalOne::checkPredict(int tableModIN, int forIN) {
    if (predictTable[tableModIN] == actual[forIN]) {
        ++numCorrect;
    } else {
        predictTable[tableModIN] = actual[forIN];
    }
}

void BiModalOne::initTable(int tableSizeIN) {
    predictTable.resize(tableSizeIN, 1);    
}

int BiModalOne::getNumBranches() {
    return numBranches;
}
