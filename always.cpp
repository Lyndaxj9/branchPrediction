#include "always.h"
#include <iostream>
#include <vector>
#include <string>

//Always constructor
Always::Always(std::vector<std::string> addrIN, std::vector<int> actualIN, int predictionIN) {
    address = addrIN;
    actual = actualIN;
    prediction = predictionIN;
    numBranches = address.size();
}

int Always::predict() {
    int numCorrect = 0;
    int check;
    
    for (int i = 0; i < numBranches; i++) {
        if (actual[i] == prediction) {
            ++numCorrect;
        }
    }
    return numCorrect;
}

int Always::getNumBranches() {
    return numBranches;
}
