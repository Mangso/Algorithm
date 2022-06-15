// 적록색약

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char Board[101][101];
int Visitied[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N;

void init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Visitied[i][j] = 0;
        }
    }
}

void BFS(int x, int y, char color) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    Visitied[x][y] = 1;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (Visitied[nx][ny] == 1 || Board[nx][ny] != color) continue;

            Visitied[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int main() {
    cin >> N;

    vector<char> Colors{'R', 'G', 'B'};
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            Board[i][j] = s[j];
        }
    }

    int normal_cnt = 0;
    for (auto color : Colors) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (Visitied[i][j] == 0 && Board[i][j] == color) {
                    BFS(i, j, color);
                    normal_cnt++;
                }
            }
        }
    }

    init();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (Board[i][j] == 'G') Board[i][j] = 'R';
        }
    }

    int unnormal_cnt = 0;
    for (auto color : {'R', 'B'}) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (Visitied[i][j] == 0 && Board[i][j] == color) {
                    BFS(i, j, color);
                    unnormal_cnt++;
                }
            }
        }
    }

    cout << normal_cnt << " " << unnormal_cnt << '\n';
    return 0;
}