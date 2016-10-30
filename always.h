#ifndef ALWAYS_H
#define ALWAYS_H
#include <vector>
#include <string>

class Always {
    private:
        std::vector<std::string> address;
        std::vector<int> actual;
        int prediction;
        int numBranches;

    public:
        Always(std::vector<std::string> addrIN, std::vector<int> actualIN, int predictionIN);
        int predict();
        int getNumBranches();
};

#endif
