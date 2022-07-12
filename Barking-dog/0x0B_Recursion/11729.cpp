// 하노이의 탑
#include <iostream>

using namespace std;

void move(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }

    // n-1개의 원판 a번 기둥에서 n-a-b번 기둥으로.
    move(a, 6 - a - b, n - 1);

    // n번 원판 a번 기둥에서 b번 기둥으로..
    cout << a << " " << b << '\n';

    // n-1개 원판 n-a-b번 기둥에서 기둥 b로.
    move(6 - a - b, b, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << '\n';
    move(1, 3, n);

    return 0;
}