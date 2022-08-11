// 문자열 지옥에 빠진 호석
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int N, M, K;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

string board[11];
unordered_map<string, int> um;

void dfs(pair<int, int> pose, string word) {
    word += board[pose.first][pose.second];
    um[word]++;

    // 문자열 조건 5 이하.
    if (int(word.size()) == 5)
        return;

    for (int dir = 0; dir < 8; dir++) {
        int nx = pose.first + dx[dir];
        int ny = pose.second + dy[dir];

        if (nx < 0) nx = N - 1;
        if (ny < 0) ny = M - 1;
        if (nx >= N) nx = 0;
        if (ny >= M) ny = 0;

        dfs({nx, ny}, word);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dfs({i, j}, "");
        }
    }

    for (int i = 0; i < K; i++) {
        string s;
        cin >> s;
        cout << um[s] << '\n';
    }

    return 0;
}