#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int Board[101][101];
int Visited[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int M, N, K;

int bfs(int x, int y) {
    queue<pair<int, int> > Q;
    Q.push({x, y});
    Visited[x][y] = true;

    int area = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        area++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (Visited[nx][ny] == true || Board[nx][ny] == 1) continue;

            Visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }

    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> K;

    for (int i = 0; i < K; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = y1; j < y2; j++)
            for (int k = x1; k < x2; k++)
                Board[j][k] = 1;
    }

    vector<int> v;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (Board[i][j] == 0 && Visited[i][j] == 0) {
                int area = bfs(i, j);
                v.push_back(area);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto ele : v) cout << ele << " ";
}