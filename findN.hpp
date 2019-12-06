#ifndef FIND_N
#define FIND_N

#include<vector>
#include<string>

std::vector<int> findN(std::string const &str, std::string const &txt) {
    std::vector<int> res;
    std::vector<int>::size_type strlen = str.size(), txtlen = txt.size();
    if (!strlen || !txtlen || strlen > txtlen) return res;

    for (std::vector<int>::size_type i = 0; i < txtlen - strlen + 1; ++i) {
        std::vector<int>::size_type j = 0;
        while (j < strlen && str[j] == txt[i + j]) {
            ++j;
        }
        if (j == strlen) {
            res.push_back(i);
        }
    }
    return res;
}

#endif