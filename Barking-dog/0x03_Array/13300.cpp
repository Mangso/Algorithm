// 방 배정
#include <iostream>
#include <vector>

int main() {
    int n, k, sex, grade;
    std::vector<std::vector<int> > v(2, std::vector<int>(6));
    std::cin >> n >> k;

    for (int i = 0; i < n; i++) {
        std::cin >> sex >> grade;
        v[sex][grade - 1]++;
    }

    int room_num = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            room_num += (v[i][j] / k);

            if (v[i][j] % k != 0)
                room_num++;
        }
    }
    std::cout << room_num;
    return 0;
}