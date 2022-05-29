#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, v;
    int cnt = 0;
    std::vector<int> arr(101);

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cin >> v;

    for (int i = 0; i < n; i++) {
        if (arr[i] == v) cnt++;
    }
    // for base 문은 모든 값이 0이 아닌 값을 갖고 있을 때 쓰자.

    std::cout << cnt;
    return 0;
}