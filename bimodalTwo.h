#ifndef BIMOTWO_H
#define BIMOTWO_H
#include <vector>
#include <string>

class BiModalTwo {
    private:
        std::vector<std::string> address;
        std::vector<int> actual;
        int numBranches;
        int numCorrect;

        std::vector<int> predictTable;

    public:
        BiModalTwo(std::vector<std::string> addrIN, std::vector<int> actualIN);
        int predict(int tableSizeIN);
        void checkPredict(int tableModIN, int forIN);
        void initTable(int tableSizeIN);
        int getNumBranches();
};

#endif
