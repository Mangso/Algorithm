// 2468 안전영역

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Area {
    int height;
    bool sink = false;
    bool visited = false;
};

Area Board[101][101];

void Init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Board[i][j].sink = false;
            Board[i][j].visited = false;
        }
    }
}

void InitSink(int h) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (Board[i][j].height <= h) {
                Board[i][j].sink = true;
            }
        }
    }
}

void BFS(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    Board[x][y].visited = true;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (Board[nx][ny].visited == true || Board[nx][ny].sink == true) continue;

            Board[nx][ny].visited = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int max_height = -1;

    // height 저장 및 최대 높이 저장
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> Board[i][j].height;

            max_height = max(max_height, Board[i][j].height);
        }
    }

    int max_unsink_area = 0;
    // h 0부터 시작해야 함 (모두 다 잠기지 않을 수도 있다고 했음)
    for (int h = 0; h <= max_height; h++) {
        // 잠긴 영역 표시
        InitSink(h);

        int cnt_area = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (Board[i][j].sink == false && Board[i][j].visited == false) {
                    BFS(i, j);
                    cnt_area++;
                }
            }
        }
        // max_unsink_area 업데이트
        max_unsink_area = max(max_unsink_area, cnt_area);
        Init();
    }

    cout << max_unsink_area;

    return 0;
}