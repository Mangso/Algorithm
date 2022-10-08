// 로봇 청소기
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 로봇
struct Robot {
    int x, y;
    int dir;
};

vector<vector<int>> board(51, vector<int>(51));
vector<vector<bool>> visited(51, vector<bool>(51));

Robot robot;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, M;

void Input() {
    cin >> N >> M;
    cin >> robot.x >> robot.y >> robot.dir;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
}

void PrintBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int ToBack(int dir) {
    if (dir == 0) return 2;
    if (dir == 1) return 3;
    if (dir == 2) return 0;
    if (dir == 3) return 1;
}

int Rotate(int dir) {
    if (dir == 0) return 3;
    if (dir == 1) return 0;
    if (dir == 2) return 1;
    if (dir == 3) return 2;
}

bool Check4(Robot& r) {
    bool flag1, flag2;
    flag1 = flag2 = false;

    for (int dir = 0; dir < 4; dir++) {
        int nx = r.x + dx[dir];
        int ny = r.y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] == 1 || visited[nx][ny] == true) continue;

        flag1 = true;
    }

    int change_dir = ToBack(r.dir);
    int nx = r.x + dx[change_dir];
    int ny = r.y + dy[change_dir];

    if (board[nx][ny] != 1) flag2 = true;

    if (!flag1 && !flag2)
        return true;
    else
        return false;
}

bool Check3(Robot& r) {
    bool flag1, flag2;
    flag1 = flag2 = false;

    for (int dir = 0; dir < 4; dir++) {
        int nx = r.x + dx[dir];
        int ny = r.y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] == 1 || visited[nx][ny] == true) continue;

        flag1 = true;
    }

    int change_dir = ToBack(r.dir);
    int nx = r.x + dx[change_dir];
    int ny = r.y + dy[change_dir];

    if (board[nx][ny] != 1) flag2 = true;

    if (!flag1 && flag2)
        return true;
    else
        return false;
}

bool Check1(Robot& r) {
    int dir = Rotate(r.dir);

    int nx = r.x + dx[dir];
    int ny = r.y + dy[dir];

    if (board[nx][ny] == 0 && visited[nx][ny] == false) {
        return true;
    } else
        return false;
}

int BFS() {
    queue<Robot> Q;
    Q.push(robot);
    visited[robot.x][robot.y] = true;
    int cnt = 1;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if (Check4(cur)) break;
        if (Check3(cur)) {
            int change_dir = ToBack(cur.dir);
            cur.x += dx[change_dir];
            cur.y += dy[change_dir];

            Q.push(cur);
            continue;
        }

        if (Check1(cur)) {
            int dir = Rotate(cur.dir);

            cur.x += dx[dir];
            cur.y += dy[dir];
            cur.dir = dir;

            visited[cur.x][cur.y] = true;
            cnt++;
            Q.push(cur);
        } else {
            int dir = Rotate(cur.dir);

            cur.dir = dir;
            Q.push(cur);
        }
    }

    return cnt;
}

void Solve() {
    cout << BFS();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();

    return 0;
}