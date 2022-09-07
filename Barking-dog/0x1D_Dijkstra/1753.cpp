// 최단 경로
#include <bits/stdc++.h>

using namespace std;

// {비용, 정점 번호}
vector<pair<int, int>> adj[20005];
vector<int> minCostTable(20005);

const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E;
    cin >> V >> E;

    int K;  // 시작 정점
    cin >> K;

    // Step1 그래프 초기화 및 최단비용테이블 초기화
    for (int i = 0; i < E; i++) {
        int u, v, w;  // 정점1 <-> 정점2, 비용
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }

    fill(minCostTable.begin(), minCostTable.begin() + V + 1, INF);

    // Step 2 우선순위 큐 만들기 (min_heap) & 최단비용 테이블 시작점 0으로.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    minCostTable[K] = 0;
    // Step 3 우선순위 큐에 시작점 추가! (0의 비용, 시작점)
    pq.push({minCostTable[K], K});

    // Step 4 우선순위 큐 빌 때까지 업데이트하기.
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        // Step 5 cur 현재 거리가 minCostTable에 있는 값과 다른 경우 넘어가기
        if (minCostTable[cur.second] != cur.first)
            continue;

        for (auto nxt : adj[cur.second]) {
            if (minCostTable[nxt.second] <= minCostTable[cur.second] + nxt.first)
                continue;

            minCostTable[nxt.second] = minCostTable[cur.second] + nxt.first;
            pq.push({minCostTable[nxt.second], nxt.second});
        }
    }

    for (int i = 1; i <= V; i++) {
        if (minCostTable[i] == INF)
            cout << "INF\n";
        else
            cout << minCostTable[i] << '\n';
    }

    return 0;
}