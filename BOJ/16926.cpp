// 배열 돌리기 1
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int N, M, R;

void print(vector<vector<int>> v) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N >> R;

    vector<vector<int>> matrix(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    int layer = min(M, N) / 2;
    vector<vector<int>> tmp;
    for (int i = 0; i < layer; i++) {
        vector<int> v;
        // top
        for (int j = i; j < N - i; j++) {
            v.push_back(matrix[i][j]);
        }

        // right
        for (int j = i + 1; j < M - i; j++) {
            v.push_back(matrix[j][N - 1 - i]);
        }
        // bottom
        for (int j = N - 2 - i; j >= i; j--) {
            v.push_back(matrix[M - 1 - i][j]);
        }
        // left
        for (int j = M - 2 - i; j > i; j--) {
            v.push_back(matrix[j][i]);
        }

        tmp.push_back(v);
    }

    // rotate elements and place it in original matrix;
    for (int i = 0; i < layer; i++) {
        vector<int> v;
        v = tmp[i];
        int row = tmp[i].size();

        int idx = R % row;

        // top
        for (int j = i; j < N - i; j++) {
            matrix[i][j] = v[idx];
            idx = (idx + 1) % row;
        }
        for (int j = i + 1; j < M - i; j++) {
            matrix[j][N - 1 - i] = v[idx];
            idx = (idx + 1) % row;
        }
        for (int j = N - 2 - i; j >= i; j--) {
            matrix[M - 1 - i][j] = v[idx];
            idx = (idx + 1) % row;
        }

        for (int j = M - 2 - i; j > i; j--) {
            matrix[j][i] = v[idx];
            idx = (idx + 1) % row;
        }
    }

    print(matrix);

    return 0;
}