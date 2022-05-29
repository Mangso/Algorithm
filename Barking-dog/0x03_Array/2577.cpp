#include <iostream>
#include <vector>

int main() {
    int a, b, c;
    int result;
    std::vector<int> v(10);

    std::cin >> a >> b >> c;

    result = a * b * c;
    while (result) {
        int tmp = result % 10;
        v[tmp]++;

        result /= 10;
    }

    for (const auto &ele : v)
        std::cout << ele << '\n';

    return 0;
}
