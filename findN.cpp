#include<iostream>
#include<string>
#include<vector>

std::vector<int> findN(std::string const &str, std::string const &txt) {
    std::vector<int> res;
    std::vector<int>::size_type strlen = str.size(), txtlen = txt.size();
    if (strlen > txtlen) return res;

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

// usage:
// int main() {
//     std::string txt = "ABCAABCABCA";
//     std::string str = "ABCA";

//     std::vector<int> pos = findN(str, txt);
//     for (int i = 0; i < pos.size(); ++i) {
//         std::cout << pos[i] << ' ';
//     }
//     std::cout << '\n';
// }