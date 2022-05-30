// 애너그램 만들기

#include <iostream>
#include <string>
#include <vector>

int Solve(const std::vector<int>& v1, const std::vector<int>& v2) {
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (v1[i] > v2[i])
            count += v1[i] - v2[i];
        else
            count += v2[i] - v1[i];
    }

    return count;
}
int main() {
    std::string str1, str2;
    std::vector<int> v1(26), v2(26);

    std::cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); i++) {
        v1[str1[i] - 'a']++;
    }

    for (int i = 0; i < str2.size(); i++) {
        v2[str2[i] - 'a']++;
    }

    std::cout << Solve(v1, v2);
    return 0;
}