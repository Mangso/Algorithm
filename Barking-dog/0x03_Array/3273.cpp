#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::vector<int> v(1000001);
    std::vector<int> exist(2000001);
    int ans = 0;

    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    std::cin >> x;

    for (int i = 0; i < n; i++) {
        if (x - v[i] > 0 && exist[x - v[i]]) {
            ans++;
        }
        exist[v[i]] = 1;
    }

    std::cout << ans;
    return 0;
}
