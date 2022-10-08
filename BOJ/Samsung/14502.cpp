// 연구소
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> board(9, vector<int>(9));
vector<vector<int>> new_board(9, vector<int>(9));

bool visited[9][9];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, M;
int max_cnt;

vector<pair<int, int>> zero_pose;
vector<pair<int, int>> virus_pose;

void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];

            if (board[i][j] == 0) zero_pose.push_back(make_pair(i, j));
            if (board[i][j] == 2) virus_pose.push_back(make_pair(i, j));
        }
    }
}

void InitVisited() {
    for (int i = 0; i < N; i++) {
        fill(visited[i], visited[i] + M, false);
    }
}

void PrintArray() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

void BFS() {
    queue<pair<int, int>> Q;
    InitVisited();

    for (int i = 0; i < virus_pose.size(); i++) {
        int x = virus_pose[i].first;
        int y = virus_pose[i].second;
        Q.push(make_pair(x, y));
        visited[x][y] = true;
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (new_board[nx][ny] != 0 || visited[nx][ny] == true) continue;

            visited[nx][ny] = true;
            new_board[nx][ny] = 2;
            Q.push(make_pair(nx, ny));
        }
    }

    int zero_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (new_board[i][j] == 0) {
                zero_cnt++;
            }
        }
    }

    max_cnt = max(max_cnt, zero_cnt);
}

void func(vector<int> result, vector<bool> isused, int idx, int depth) {
    if (depth == 3) {
        new_board = board;
        for (int i = 0; i < depth; i++) {
            new_board[zero_pose[result[i]].first][zero_pose[result[i]].second] = 1;
        }
        BFS();
        return;
    }

    for (int i = idx; i < zero_pose.size(); i++) {
        if (!isused[i]) {
            isused[i] = true;
            result[depth] = i;
            func(result, isused, i + 1, depth + 1);
            isused[i] = false;
        }
    }
}

void Solve() {
    // PrintArray();
    vector<int> result(3);
    vector<bool> isused(zero_pose.size(), false);
    func(result, isused, 0, 0);

    cout << max_cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();

    return 0;
}