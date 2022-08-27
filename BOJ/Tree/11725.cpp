// 트리의 부모 찾기
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
int p[100001];

void dfs(int cur) {
    for (int nxt : adj[cur]) {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) {
        cout << p[i] << '\n';
    }
    return 0;
}