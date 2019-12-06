#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>

#include"findN.hpp"
#include"findKMP.hpp"

std::string randomString(size_t len) {
    string result;
    for (size_t i = 0; i < len; ++i) {
        result += 'A' + rand() % 2;
    }
    return result;
}

void test (std::vector<int> &resN, std::vector<int> &resKMP, 
std::string const &str, std::string const &txt) {

    resN = findN(str, txt);
    resKMP = resKMP = findKMP(str, txt);
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
        test(resN, resKMP, randomString(5*i), randomString(50*i));
    }
}

int main() {
    srand(time(a));
    tests();
}