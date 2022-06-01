#include <iostream>
#include <list>
#include <string>

int main() {
    std::string s;
    int n;

    std::cin >> s >> n;

    std::list<char> l;
    for (auto ele : s) l.push_back(ele);

    auto cur_ptr = l.end();
    for (int i = 0; i < n; i++) {
        char command, c;
        std::cin >> command;
        if (command == 'P') {
            std::cin >> c;
            l.insert(cur_ptr, c);
        } else if (command == 'L') {
            if (cur_ptr != l.begin()) cur_ptr--;
        } else if (command == 'D') {
            if (cur_ptr != l.end()) cur_ptr++;
        } else if (command == 'B') {
            if (cur_ptr != l.begin()) {
                cur_ptr--;
                cur_ptr = l.erase(cur_ptr);
            }
        }
    }

    for (auto ele : l) std::cout << ele;
    return 0;
}