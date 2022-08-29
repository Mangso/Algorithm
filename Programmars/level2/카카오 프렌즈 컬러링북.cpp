#include <queue>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<bool>> visited(m, vector<bool>(n));

    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            int area = 0;
            if (visited[x][y] == false && picture[x][y] != 0) {
                number_of_area++;
                queue<pair<int, int>> Q;
                Q.push({x, y});
                visited[x][y] = true;

                int p = picture[x][y];

                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    area++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= m || ny < 0 || ny > n) continue;
                        if (visited[nx][ny] == true || picture[nx][ny] != p) continue;

                        visited[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, area);
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}