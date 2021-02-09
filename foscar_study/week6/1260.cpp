// DFS와 BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visited[1001];
vector<int> adj[1001];

void dfs(int pos)
{
    // 현재 좌표 출력
    cout << pos << ' ';
    // 방문했다 표시
    visited[pos] = 1;

    // 돌면서 방문 안한거 순회시작.
    for (auto &i : adj[pos])
    {
        if (!visited[i])
            dfs(i);
    }
}

void bfs(int pos)
{
    queue<int> q;
    // 큐 시작점
    q.push(pos);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        // 방문한 칸이면 넘어감.
        if (visited[vertex])
            continue;

        // 방문 안한 경우 출력 후 방문처리
        cout << vertex << ' ';
        visited[vertex] = 1;

        for (auto &i : adj[vertex])
            if (!visited[i])
                q.push(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(v);
    cout << '\n';
    // 초기화
    fill(visited, visited + 1001, 0);
    bfs(v);

    return 0;
}