#include <array>
#include <iostream>
#include <string>

int main() {
    std::string word;
    std::cin >> word;

    std::array<int, 26> arr = {0};

    for (const auto &ele : word) {
        arr[ele - 'a']++;
    }

    for (const auto &ele : arr) {
        std::cout << ele << ' ';
    }

    return 0;
}