#include <bits/stdc++.h>

using namespace std;

int board[21][21];
int N, M, K;
vector<int> commands;

struct Dice {
    int x, y;
    int arr[7];
};

Dice dice;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void Input() {
    cin >> N >> M >> dice.x >> dice.y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int n;
    for (int i = 0; i < K; i++) {
        cin >> n;
        commands.push_back(n);
    }
}

void rotateDice(int num, Dice tmp_dice) {
    // 동쪽
    if (num == 1) {
        dice.arr[6] = tmp_dice.arr[3];
        dice.arr[3] = tmp_dice.arr[1];
        dice.arr[1] = tmp_dice.arr[4];
        dice.arr[4] = tmp_dice.arr[6];
    } else if (num == 2) {
        dice.arr[6] = tmp_dice.arr[4];
        dice.arr[4] = tmp_dice.arr[1];
        dice.arr[1] = tmp_dice.arr[3];
        dice.arr[3] = tmp_dice.arr[6];
    } else if (num == 3) {
        dice.arr[5] = tmp_dice.arr[6];
        dice.arr[1] = tmp_dice.arr[5];
        dice.arr[2] = tmp_dice.arr[1];
        dice.arr[6] = tmp_dice.arr[2];
    } else if (num == 4) {
        dice.arr[6] = tmp_dice.arr[5];
        dice.arr[5] = tmp_dice.arr[1];
        dice.arr[1] = tmp_dice.arr[2];
        dice.arr[2] = tmp_dice.arr[6];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();

    for (auto ele : commands) {
        int nx = dice.x + dx[ele - 1];
        int ny = dice.y + dy[ele - 1];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        rotateDice(ele, dice);

        if (board[nx][ny] != 0) {
            dice.arr[6] = board[nx][ny];
            board[nx][ny] = 0;
        } else {
            board[nx][ny] = dice.arr[6];
        }

        // for (int i = 1; i <= 6; i++) {
        //     cout << i << " : " << dice.arr[i] << '\n';
        // }

        cout << dice.arr[1] << '\n';
        dice.x = nx;
        dice.y = ny;
    }

    return 0;
}