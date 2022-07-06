// 2667 단지 번호 붙이기
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int Board[26][26];
int Visited[26][26];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(int x, int y) {
    queue<pair<int, int>> Q;
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

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (Visited[nx][ny] == true || Board[nx][ny] == 0) continue;

            Visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }

    return area;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            Board[i][j] = int(s[j] - '0');
        }
    }

    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         cout << Board[i][j];
    //     }
    //     cout << '\n';
    // }

    vector<int> houses;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (Visited[i][j] == 0 && Board[i][j] == 1) {
                int area = BFS(i, j);
                houses.push_back(area);
            }
        }
    }

    sort(houses.begin(), houses.end());
    cout << houses.size() << '\n';
    for (const auto &e : houses) {
        cout << e << '\n';
    }

    return 0;
}
