#ifndef findKMP_HPP
#define findKMP_HPP

#include <vector>
#include <string>
#include <iostream>

std::vector<int> findKMP(std::string const &str, std::string const &text) {
    if (!text.length() || !str.length() || text.length() < str.length()) {
        return {};
    }
    int tableKMP[str.length() + 1];
    tableKMP[0] = -1;
    int kmpIndex = 1;
    int strIndex = 0;
    while (kmpIndex < str.length()) {
        if (str[kmpIndex] == str[strIndex]) {
            tableKMP[kmpIndex] = tableKMP[strIndex];
        } else {
            tableKMP[kmpIndex] = strIndex;
            strIndex = tableKMP[strIndex];
            while (strIndex >= 0 && str[kmpIndex] != str[strIndex]) {
                strIndex = tableKMP[strIndex];
            }
        }
        ++kmpIndex;
        ++strIndex;
    }
    tableKMP[kmpIndex] = strIndex;
    
    
    std::vector<int> result;
    int strPos = 0;
    int textPos = 0;
    while (textPos < text.length()) {
            if (str[strPos] == text[textPos]) {
                ++strPos;
                ++textPos;
                if (strPos == str.length()) {
                    result.push_back(textPos - strPos);
                    strPos = tableKMP[strPos];
                }
            } else {
                strPos = tableKMP[strPos];
                if (strPos < 0) {
                    ++strPos;
                    ++textPos;
                }
            }
    }
    return result;
}
#endif