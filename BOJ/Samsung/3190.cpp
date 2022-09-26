// 뱀
#include <bits/stdc++.h>

using namespace std;

int board[102][102];
vector<pair<int, char>> directions;
pair<int, int> head;

deque<pair<int, int>> snake;
int N, K, L;
int dir;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void Input() {
    int x, y;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        board[x][y] = 1;
    }

    cin >> L;

    pair<int, char> info;
    for (int i = 0; i < L; i++) {
        cin >> info.first >> info.second;
        directions.push_back(info);
    }

    // Snake 머리
    head.first = 1;
    head.second = 1;

    board[1][1] = 3;

    snake.push_front(head);
}

int Change(int d, char c) {
    if (c == 'D') {
        d++;
    } else {
        d--;
    }

    if (d == 4) d = 0;
    if (d == -1) d = 3;

    return d;
}

void print() {
    cout << '\n';
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    // 1. Step 1 Input
    Input();

    int time = 0;
    int idx = 0;
    while (true) {
        // 방향 전환
        if (time == directions[idx].first) {
            dir = Change(dir, directions[idx].second);
            idx++;
        }

        // 몸 길이 늘리기.
        int nx = head.first + dx[dir];
        int ny = head.second + dy[dir];

        time++;

        // 벽 부딪히거나, 머리가 몸에 부딪혔을 때.
        if (nx <= 0 || nx > N || ny <= 0 || ny > N)
            break;
        if (board[nx][ny] == 3)
            break;

        // 사과 먹었을 때,
        if (board[nx][ny] == 1) {
            board[nx][ny] = 3;
            snake.push_front({nx, ny});
            head = {nx, ny};
        } else {
            board[nx][ny] = 3;
            snake.push_front({nx, ny});
            head = {nx, ny};
            auto tail = snake.back();
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }
    }

    cout << time;
    return 0;
}