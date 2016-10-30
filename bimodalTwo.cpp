#include "bimodalTwo.h"
#include <iostream>
#include <sstream>

//CONSTRUCTOR
BiModalTwo::BiModalTwo(std::vector<std::string> addrIN, std::vector<int> actualIN) {
    address = addrIN;
    actual = actualIN;
    numBranches = address.size();
    numCorrect = 0;
}

int BiModalTwo::predict(int tableSizeIN) {
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
        ss.str("");
    } 
    return numCorrect;
}

void BiModalTwo::checkPredict(int tableModIN, int forIN) {
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

void BiModalTwo::initTable(int tableSizeIN) {
    predictTable.clear();
    numCorrect = 0;
    predictTable.resize(tableSizeIN, 3);    
}

int BiModalTwo::getNumBranches() {
    return numBranches;
}
