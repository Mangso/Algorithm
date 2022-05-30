// Strfry
#include <algorithm>
#include <iostream>
#include <string>

std::string CheckStrfry(const std::string& str1, const std::string& str2) {
    if (str1 == str2) return "Possible";
    return "Impossible";
}

int main() {
    int n;
    std::string str1, str2;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> str1 >> str2;
        std::sort(str1.begin(), str1.end());
        std::sort(str2.begin(), str2.end());
        std::cout << CheckStrfry(str1, str2) << "\n";
    }

    return 0;
}