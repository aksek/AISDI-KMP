#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cassert>

#include"findN.hpp"
#include"findKMP.hpp"

std::string randomString(size_t len, size_t alphSize) {
    if (alphSize > 'Z' - 'A' + 1) alphSize = 'Z' - 'A' + 1;
    std::string result;
    for (size_t i = 0; i < len; ++i) {
        result += 'A' + rand() % alphSize;
    }
    return result;
}

void test (std::vector<int> &resN, std::vector<int> &resKMP, 
std::string const &str, std::string const &txt) {

    resN = findN(str, txt);
    resKMP = findKMP(str, txt);
    assert(resN == resKMP);
 }

void tests() {
    std::vector<int> resN;
    std::vector<int> resKMP;

    test(resN, resKMP, "", "");
    test(resN, resKMP, "ABC", "ABC");
    test(resN, resKMP, "ABCA", "ABC");
    test(resN, resKMP, "AA", "ABC");

    for (int i = 0; i < 10; ++i) {
        test(resN, resKMP, randomString(5, 3), randomString(50, 3));
    }
}

int main() {
    srand(time(0));
    tests();
}