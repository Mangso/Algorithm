// 키로거
#include <iostream>
#include <list>
#include <string>

void GetPassword(const std::string& s) {
    std::list<char> l;

    auto cursor = l.begin();
    for (const auto& ele : s) {
        if (ele == '<') {
            if (cursor != l.begin())
                cursor--;
        } else if (ele == '>') {
            if (cursor != l.end())
                cursor++;
        } else if (ele == '-') {
            if (cursor != l.begin()) {
                cursor--;
                cursor = l.erase(cursor);  // 커서 왼쪽으로 옮기고 지우기
            }
        } else {
            l.insert(cursor, ele);
        }
    }

    for (const auto& ele : l) std::cout << ele;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        GetPassword(s);
        std::cout << '\n';
    }
}