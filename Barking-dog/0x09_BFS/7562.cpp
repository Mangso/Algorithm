// 7562 나이트의 이동

#include <iostream>
#include <queue>

using namespace std;

const int SIZE = 301;

struct Knight {
    int x;
    int y;
    int dist;
    bool visited = false;
};

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

Knight Board[SIZE][SIZE];

int board_size;

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    Board[x][y].visited = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= board_size || ny >= board_size) continue;
            if (Board[nx][ny].visited == true) continue;

            Board[nx][ny].visited = true;
            Board[nx][ny].dist = Board[cur.first][cur.second].dist + 1;
            q.push({nx, ny});
        }
    }
}

void Init() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            Board[i][j].dist = 0;
            Board[i][j].visited = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        Init();
        cin >> board_size;
        int cur_pose_x, cur_pose_y;
        int target_pose_x, target_pose_y;
        cin >> cur_pose_x >> cur_pose_y >> target_pose_x >> target_pose_y;

        BFS(cur_pose_x, cur_pose_y);

        cout << Board[target_pose_x][target_pose_y].dist << '\n';
    }

    return 0;
}