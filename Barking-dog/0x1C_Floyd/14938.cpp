// 서강그라운드
#include <bits/stdc++.h>

using namespace std;

int Graph[110][110];
int item[1010];

const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r;  // 정점, 수색범위, 간선
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }
    for (int i = 1; i <= n; i++) {
        fill(Graph[i], Graph[i] + n + 1, INF);
    }

    for (int i = 0; i < r; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u][v] = min(Graph[u][v], w);
        Graph[v][u] = min(Graph[v][u], w);
    }
    // 자기자신 초기화
    for (int i = 1; i <= n; i++) Graph[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (Graph[i][k] + Graph[k][j] < Graph[i][j]) {
                    Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (Graph[i][j] <= m) cnt += item[j];
        }
        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}