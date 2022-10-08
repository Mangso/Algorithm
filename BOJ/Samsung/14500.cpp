// 테트로미노
#include <bits/stdc++.h>

using namespace std;

int board[501][501];
bool visited[501][501];

int N, M;
int answer;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
}

void PrintBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

void DFS(int x, int y, int sum, int depth) {
    if (depth == 3) {
        answer = max(answer, sum);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visited[nx][ny] == true) continue;

        visited[nx][ny] = true;
        DFS(nx, ny, sum + board[nx][ny], depth + 1);
        visited[nx][ny] = false;
    }
}

void Init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
}

void findFuckShapeMax(int x, int y) {
    //ㅜ
    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < M) {
        int sum = board[x][y] + board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1];
        answer = max(answer, sum);
    }

    // ㅗ
    if (x + 1 < N && y - 1 >= 0 && y + 1 < M) {
        int sum = board[x][y] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1];
        answer = max(answer, sum);
    }

    // ㅏ
    if (x - 1 >= 0 && x + 1 < N && y - 1 >= 0) {
        int sum = board[x][y] + board[x - 1][y - 1] + board[x][y - 1] + board[x + 1][y - 1];
        answer = max(answer, sum);
    }

    // ㅓ
    if (x - 1 >= 0 && x + 1 < N && y + 1 < M) {
        int sum = board[x][y] + board[x - 1][y + 1] + board[x][y + 1] + board[x + 1][y + 1];
        answer = max(answer, sum);
    }
}

void Solve() {
    // Step 2. 모든 좌표에서 depth가 3인 DFS (Backtracking)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            findFuckShapeMax(i, j);

            visited[i][j] = true;
            DFS(i, j, board[i][j], 0);
            visited[i][j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();

    cout << answer;

    return 0;
}