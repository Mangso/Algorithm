// 토마토

#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int SIZE = 1001;

int board[SIZE][SIZE];
int visited[SIZE][SIZE];
int dist[SIZE][SIZE];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int x, int y) {
    return x < 0 || y < 0 || x >= SIZE || y >= SIZE;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < SIZE; i++) fill(board[i], board[i] + SIZE, -1);

    int m, n;
    cin >> m >> n;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 1) q.push({i, j});
            if (board[i][j] == 0) dist[i][j] = -1;
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (OOB(nx, ny)) continue;
            if (dist[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            answer = max(answer, dist[i][j]);
        }
    }

    cout << answer;
}