// 쿼드 트리
#include <iostream>
#include <vector>

using namespace std;

int N;

int Image[65][65];

void Recur(int x, int y, int n) {
    if (n == 1) {
        cout << Image[x][y];
        return;
    }

    bool zero, one;
    zero = true;
    one = true;

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (Image[i][j] == 0)
                one = false;
            if (Image[i][j] == 1)
                zero = false;
        }
    }

    if (zero == true) {
        cout << 0;
        return;
    }
    if (one == true) {
        cout << 1;
        return;
    }

    cout << "(";
    Recur(x, y, n / 2);
    Recur(x, y + n / 2, n / 2);
    Recur(x + n / 2, y, n / 2);
    Recur(x + n / 2, y + n / 2, n / 2);
    cout << ")";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (size_t j = 0; j < s.size(); j++) {
            Image[i][j] = s[j] - '0';
        }
    }

    Recur(0, 0, N);

    return 0;
}