#ifndef GSHARE_H
#define GSHARE_H
#include <vector>
#include <string>

class Gshare {
    private:
        std::vector<std::string> address;
        std::vector<int> actual;
        int numBranches;
        int numCorrect;

        std::vector<int> predictTable;
        int tableSize = 2048;
        int ghr = 0;

    public:
        Gshare(std::vector<std::string> addrIN, std::vector<int> actualIN);
        int predict(int historyLengthIN);
        void checkPredict(int tableModIN, int forIN);
        void initTable();
        int getNumBranches();
};

#endif
