//1325 효율적인 해킹
// DFS
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> adj[10001];
int visited[10001];
int hacking[10001];

int cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int nMax = 0;
    cin >> n >> m;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));

        visited[i] = 1;

        stack<int> s;
        s.push(i);
        int cnt = 1;

        while (!s.empty())
        {
            int cur = s.top();
            s.pop();
            for (auto near : adj[cur])
            {
                if (!visited[near])
                {
                    visited[near] = true;
                    s.push(near);
                    cnt++;
                }
            }

            hacking[i] = cnt;
            nMax = max(nMax, cnt);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (hacking[i] == nMax)
            cout << i << " ";
    }

    return 0;
}