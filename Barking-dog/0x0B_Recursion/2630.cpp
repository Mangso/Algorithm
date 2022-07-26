// 종이의 개수

#include <iostream>

using namespace std;

const int MX = 128;

int board[MX][MX];
int answer[2];

bool check(int n, int x, int y) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[i][j] != board[x][y])
                return false;
        }
    }
    return true;
}

void recur(int n, int x, int y) {
    if (check(n, x, y)) {
        answer[board[x][y]]++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            recur(n / 2, x + i * n / 2, y + j * n / 2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    recur(N, 0, 0);
    for (auto ele : answer)
        cout << ele << '\n';

    return 0;
}