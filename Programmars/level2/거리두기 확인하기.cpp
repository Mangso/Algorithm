#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

const int MX = 5;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool visited[MX][MX];

void Init() {
    for (int i = 0; i < MX; i++) {
        for (int j = 0; j < MX; j++) {
            visited[i][j] = false;
        }
    }
}

int BFS(int x, int y, vector<string> p) {
    Init();
    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});
    visited[x][y] = true;
    bool keep_distance = true;

    while (!q.empty()) {
        int x, y, dist;
        tie(x, y, dist) = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= MX || ny < 0 || ny >= MX) continue;
            if (visited[nx][ny] || p[nx][ny] == 'X') continue;

            if (p[nx][ny] == 'P') {
                if (dist + 1 <= 2) {
                    keep_distance = false;
                }
            }

            q.push({nx, ny, dist + 1});
            visited[nx][ny] = true;
        }
        if (!keep_distance) break;
    }

    return keep_distance;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto p : places) {
        bool keep_distance = true;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (p[i][j] == 'P') {
                    keep_distance = BFS(i, j, p);
                    if (keep_distance == false) {
                        break;
                    }
                }
            }
            if (!keep_distance) break;
        }

        if (!keep_distance)
            answer.push_back(0);
        else
            answer.push_back(1);
    }

    return answer;
}