// 유기농 배추

#include <iostream>
#include <queue>

using namespace std;

int Board[51][51];
int visited[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int M, N, K;

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Board[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int OOB(int x, int y) {
    return x < 0 || y < 0 || x >= N || y >= M;
}

void BFS(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    visited[x][y] = 1;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (OOB(nx, ny)) continue;
            if (visited[nx][ny] == 1 || Board[nx][ny] == 0) continue;

            visited[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;

        init();
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            Board[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (visited[i][j] == 0 && Board[i][j] == 1) {
                    BFS(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
}