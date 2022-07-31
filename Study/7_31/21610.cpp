// 마법사 상어와 비바라기
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

struct Bucket {
    int x, y;
    int water;
    bool cloud = false;
};

Bucket board[52][52];
int N, M;

vector<pair<int, int>> clouds_pose;

int ChangePose(int x) {
    if (x <= 0) return N;
    if (x > N) return 1;

    return x;
}

void Move(pair<int, int> info) {
    int dir = info.first - 1;
    int move_cnt = info.second;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            board[i][j].cloud = false;
        }
    }

    for (int i = 0; i < clouds_pose.size(); i++) {
        int x = clouds_pose[i].first;
        int y = clouds_pose[i].second;

        int nx = x;
        int ny = y;

        for (int j = 0; j < move_cnt; j++) {
            nx += dx[dir];
            ny += dy[dir];

            nx = ChangePose(nx);
            ny = ChangePose(ny);
        }

        clouds_pose[i].first = nx;
        clouds_pose[i].second = ny;
    }

    for (auto ele : clouds_pose) {
        board[ele.first][ele.second].cloud = true;
    }
}

void MakeRain() {
    for (const auto& ele : clouds_pose) {
        board[ele.first][ele.second].water++;
    }
}

void CopyWater() {
    for (const auto& ele : clouds_pose) {
        int cnt = 0;
        for (int dir = 1; dir < 8; dir += 2) {
            int nx = ele.first + dx[dir];
            int ny = ele.second + dy[dir];

            if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
            if (board[nx][ny].water >= 1) cnt++;
        }

        board[ele.first][ele.second].water += cnt;
    }
}
void Print() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << board[i][j].water << " ";
        }
        cout << '\n';
    }

    cout << '\n';
}

void InitCloud() {
    clouds_pose.push_back({N, 1});
    clouds_pose.push_back({N, 2});
    clouds_pose.push_back({N - 1, 1});
    clouds_pose.push_back({N - 1, 2});
    board[N][1].cloud = true;
    board[N][2].cloud = true;
    board[N - 1][1].cloud = true;
    board[N - 1][2].cloud = true;
}

void MakeCloud() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j].cloud == true || board[i][j].water < 2) continue;
            clouds_pose.push_back({i, j});
            board[i][j].water -= 2;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            board[i][j].cloud = false;
        }
    }

    for (const auto& ele : clouds_pose) {
        board[ele.first][ele.second].cloud = true;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j].water;
        }
    }

    vector<pair<int, int>> moves(M);
    for (int i = 0; i < M; i++) {
        cin >> moves[i].first >> moves[i].second;
    }

    InitCloud();
    for (const auto ele : moves) {
        Move(ele);

        // cout << "Move\n";
        // Print();

        // cout << "MakeRain\n";
        MakeRain();
        // Print();

        // cout << "CopyWater\n";
        CopyWater();

        // Print();
        clouds_pose.clear();

        // cout << "Makecloud\n";
        MakeCloud();

        // Print();
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum += board[i][j].water;
        }
    }

    cout << sum << '\n';
    return 0;
}