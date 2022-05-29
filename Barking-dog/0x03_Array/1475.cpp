// 방 번호
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    int plastic_set = 0;
    std::vector<int> v(10);
    std::vector<int> room_num;

    std::cin >> n;

    while (n) {
        int tmp = n % 10;
        room_num.push_back(tmp);
        n /= 10;
    }

    for (const auto &ele : room_num) {
        if (ele == 9)
            v[6]++;
        else
            v[ele]++;
    }

    // 1 더하는 것을 생각 못함 안일하게 넘어 감.
    v[6]++;
    v[6] /= 2;
    std::cout << *(max_element(v.begin(), v.end()));

    return 0;
}