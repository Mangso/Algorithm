#include <iostream>

int main(void) {
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
    return 0;
}