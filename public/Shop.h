#if 0
    TMP=$(mktemp -d)
    c++ -std=c++11 -I src -o ${TMP}/a.out ${0} && ${TMP}/a.out ${@:1} ; RV=${?}
    rm -rf ${TMP}
    exit ${RV}
#endif

#include <iostream>
#include <vector>
#include <string>
#include "rapidcsv.h"

class shop{
private:
    std::map<std::vector<int>, std::vector<std::string>> booksDetals;
    std::map<std::vector<int>, std::vector<std::string>> userDetails;
    std::map<std::vector<int>, std::vector<std::string>> registeredBooks;
    public:
    void assignValues();
    void getUsers();
    bool checkIfValudUser();
    void viewList();
    void registerBook();
    void viewRegisteredList();
    void options();
    void recursion();
};
