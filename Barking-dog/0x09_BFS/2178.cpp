// 미로 탐색

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int SIZE = 101;

int board[SIZE][SIZE];
int visited[SIZE][SIZE];
int dist[SIZE][SIZE];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool OOB(int x, int y) {
    return x < 0 || y < 0 || x >= SIZE || y >= SIZE;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push({x, y});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (OOB(nx, ny)) continue;
            if (visited[nx][ny] == 1 || board[nx][ny] == 0) continue;

            visited[nx][ny] = 1;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            board[i][j] = int(s[j] - '0');
        }
    }

    bfs(0, 0);

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << dist[n - 1][m - 1] + 1;
}