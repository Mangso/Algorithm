#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int SIZE = 501;

int board[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int max_area = 0;
int cnt_area = 0;

bool OOB(int x, int y) {
    return x < 0 || y < 0 || x >= SIZE || y >= SIZE;
}

int bfs(int x, int y) {
    // Step 1 시작점을 방문 처리 후 Q에 넣기
    std::queue<std::pair<int, int> > q;
    visited[x][y] = 1;
    q.push({x, y});

    // Step 2 Queue가 빌 때 까지 상하좌우 확인
    int area = 0;
    while (!q.empty()) {
        // Step 3 front 좌표 저장 후 pop
        auto cur = q.front();
        q.pop();

        // 그림의 넓이 세기
        area++;
        // std::cout << cur.first << ", " << cur.second << ") -> ";
        // Step 4 상하좌우 확인
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            // Step 5 범위 넘는지 확인
            if (OOB(nx, ny)) continue;

            // 이미 방문 했거나 그림이 아닌 경우
            if (visited[nx][ny] == 1 || board[nx][ny] == 0) continue;

            // Step 7 방문 처리
            visited[nx][ny] = 1;

            // Step 8 Q에 push
            q.push({nx, ny});
        }
    }

    return area;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> board[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 1 && visited[i][j] != 1) {
                cnt_area++;
                max_area = std::max(max_area, bfs(i, j));
            }
        }
    }

    std::cout << cnt_area << '\n';
    std::cout << max_area << '\n';

    return 0;
}