#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "always.h"
#include "bimodalOne.h"
#include "bimodalTwo.h"
#include "gshare.h"

int main(int argc, char *argv[]) {
    int count = 0;
    int taken = 1;
    int notTaken = 0;
    std::string inputFile = "../traces/short_trace1.txt";
    std::string outputFile = "output.txt";

    std::vector<std::string> address;
    std::vector<int> branch;

    if(argc == 2) {
        inputFile = argv[1];
    }


    std::ifstream infile(inputFile);
    std::string a, b;
    while (infile >> a >> b) {
        address.push_back(a);
        if (b == "T") {
            branch.push_back(1);
        } else {
            branch.push_back(0);
        }
        ++count;
    }

    Always alwaysTaken (address, branch, taken);
    Always alwaysNotTaken (address, branch, notTaken);

    BiModalOne oneBit16 (address, branch);
    BiModalOne oneBit32 (address, branch);
    BiModalOne oneBit128 (address, branch);
    BiModalOne oneBit256 (address, branch);
    BiModalOne oneBit512 (address, branch);
    BiModalOne oneBit1024 (address, branch);
    BiModalOne oneBit2048 (address, branch);

    BiModalTwo twoBit (address, branch);

    Gshare gshare (address, branch);


    std::cout << alwaysTaken.predict() << ',' << alwaysTaken.getNumBranches() << ';' << std::endl;
    std::cout << alwaysNotTaken.predict() << ',' << alwaysNotTaken.getNumBranches() << ';' << std::endl;

    std::cout << oneBit16.predict(16) << ',' << oneBit16.getNumBranches() << "; ";
    std::cout << oneBit32.predict(32) << ',' << oneBit32.getNumBranches() << "; ";
    std::cout << oneBit128.predict(128) << ',' << oneBit128.getNumBranches() << "; ";
    std::cout << oneBit256.predict(256) << ',' << oneBit256.getNumBranches() << "; ";
    std::cout << oneBit512.predict(512) << ',' << oneBit512.getNumBranches() << "; ";
    std::cout << oneBit1024.predict(1024) << ',' << oneBit1024.getNumBranches() << "; ";
    std::cout << oneBit2048.predict(2048) << ',' << oneBit2048.getNumBranches() << ';' << std::endl;

    std::cout << twoBit.predict(16) << ',' << twoBit.getNumBranches() << "; ";
    std::cout << twoBit.predict(32) << ',' << twoBit.getNumBranches() << "; ";
    std::cout << twoBit.predict(128) << ',' << twoBit.getNumBranches() << "; ";
    std::cout << twoBit.predict(256) << ',' << twoBit.getNumBranches() << "; ";
    std::cout << twoBit.predict(512) << ',' << twoBit.getNumBranches() << "; ";
    std::cout << twoBit.predict(1024) << ',' << twoBit.getNumBranches() << "; ";
    std::cout << twoBit.predict(2048) << ',' << twoBit.getNumBranches() << ";" << std::endl;

    std::cout << gshare.predict (3) << ',' << gshare.getNumBranches() << "; ";
    std::cout << gshare.predict (4) << ',' << gshare.getNumBranches() << "; ";
    std::cout << gshare.predict (5) << ',' << gshare.getNumBranches() << "; ";
    std::cout << gshare.predict (6) << ',' << gshare.getNumBranches() << "; ";
    std::cout << gshare.predict (7) << ',' << gshare.getNumBranches() << "; ";
    std::cout << gshare.predict (8) << ',' << gshare.getNumBranches() << "; ";
    std::cout << gshare.predict (9) << ',' << gshare.getNumBranches() << "; ";
    std::cout << gshare.predict (10) << ',' << gshare.getNumBranches() << "; ";
    std::cout << gshare.predict (11) << ',' << gshare.getNumBranches() << "; " << std::endl;
    
    /*
    for(int i = 0; i<initSize; i++) {
        std::cout << address[i] << std::endl;
        std::cout << branch[i] << std::endl;
    }
    */

    return 0;
}
