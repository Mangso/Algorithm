// Puyo Puyo

#include <iostream>
#include <queue>
#include <string>

using namespace std;

char board[12][6];
bool visited[12][6];

bool flag = true;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void Init() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            visited[i][j] = false;
        }
    }
}
void BFS(int x, int y) {
    queue<pair<int, int>> q, pop_pos;
    visited[x][y] = true;
    q.push({x, y});
    pop_pos.push({x, y});

    char color = board[x][y];
    int pop_cnt = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (visited[nx][ny] == true || board[nx][ny] != color) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
            pop_pos.push({nx, ny});
            pop_cnt++;
        }
    }

    if (pop_cnt >= 4) {
        flag = true;

        while (!pop_pos.empty()) {
            auto cur = pop_pos.front();
            board[cur.first][cur.second] = '.';
            pop_pos.pop();
        }
    }
}

void down() {
    for (int j = 0; j < 6; j++) {
        for (int i = 11; i >= 0; i--) {
            if (board[i][j] != '.') {
                for (int k = 11; k > i; k--) {
                    if (board[k][j] == '.') {
                        board[k][j] = board[i][j];
                        board[i][j] = '.';
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++) {
            board[i][j] = s[j];
        }
    }

    int ans = 0;
    while (true) {
        flag = false;
        Init();

        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] != '.' && visited[i][j] != true) {
                    BFS(i, j);
                }
            }
        }
        // 한번이라도 pop 된 경우가 없으면!
        if (!flag) break;

        //
        ans++;
        down();
    }

    cout << ans;
    return 0;
}
