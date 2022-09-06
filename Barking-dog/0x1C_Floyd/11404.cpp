// 플로이드
#include <bits/stdc++.h>

using namespace std;

int Graph[105][105];
int nxt[105][105];

const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;  // 정점, 간선
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        fill(Graph[i], Graph[i] + n + 1, INF);
    // 행렬 초기화 및 nxt 행렬 초기화

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u][v] = min(Graph[u][v], w);
        nxt[u][v] = v;
    }

    for (int i = 1; i <= n; i++) Graph[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (Graph[i][k] + Graph[k][j] < Graph[i][j]) {
                    Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (Graph[i][j] == INF)
                cout << "0 ";
            else
                cout << Graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}