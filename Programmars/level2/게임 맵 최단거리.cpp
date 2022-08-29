#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dist[101][101];

int BFS(int a, int b, int n, int m, vector<vector<int>> &maps) {
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 0;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0 || maps[nx][ny] != 1) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }

    if (dist[n - 1][m - 1] == -1)
        return -1;
    else
        return dist[n - 1][m - 1] + 1;
}

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);

    int answer = BFS(0, 0, n, m, maps);
    return answer;
}