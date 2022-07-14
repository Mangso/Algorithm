// 종이의 개수
#include <iostream>

using namespace std;

const int MX = 2200;

int N;
int paper[MX][MX];
int cnt[3];

bool Check(int x, int y, int n) {
    int start = paper[x][y];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (paper[i + x][j + y] != start) {
                return false;
            }
        }
    }
    return true;
}

void divide(int x, int y, int n) {
    if (Check(x, y, n)) {
        cnt[paper[x][y] + 1]++;
        return;
    }
    int size = n / 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            divide(x + i * size, y + j * size, size);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> paper[i][j];
        }
    }

    divide(0, 0, N);

    for (int i = 0; i < 3; i++) {
        cout << cnt[i] << '\n';
    }
    return 0;
}