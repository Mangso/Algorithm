// 최소 비용 구하기 2
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[1010];
vector<int> minCostTable(1010);
vector<int> pre(1005);

const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;  // 정점, 간선
    cin >> n >> m;

    // 1. 그래프 초기화 및 테이블 초기화
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    fill(minCostTable.begin(), minCostTable.begin() + n + 1, INF);

    // 2. min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int st, en;
    cin >> st >> en;
    minCostTable[st] = 0;
    pq.push({minCostTable[st], st});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (minCostTable[cur.second] != cur.first) {
            continue;
        }

        for (auto nxt : adj[cur.second]) {
            if (minCostTable[nxt.second] <= minCostTable[cur.second] + nxt.first) {
                continue;
            }

            minCostTable[nxt.second] = minCostTable[cur.second] + nxt.first;
            pq.push({minCostTable[nxt.second], nxt.second});
            pre[nxt.second] = cur.second;
        }
    }

    cout << minCostTable[en] << '\n';
    vector<int> path;
    int cur = en;
    while (cur != st) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);

    reverse(path.begin(), path.end());
    cout << path.size() << '\n';

    for (auto ele : path) {
        cout << ele << ' ';
    }

    return 0;
}