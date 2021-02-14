// 구슬 찾기

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> h[100], l[100];
bool visited[100];
int cnt = 0;

// 가벼운 순.
void ldfs(int pos)
{
    visited[pos] = true;

    for (auto i : l[pos])
    {
        if (!visited[i])
        {
            ++cnt;
            ldfs(i);
        }
    }
}

// 무거운 순
void hdfs(int pos)
{
    visited[pos] = true;

    for (auto i : h[pos])
    {
        if (!visited[i])
        {
            ++cnt;
            hdfs(i);
        }
    }
}
int main()
{
    int n, m;
    int result = 0;
    cin >> n >> m;

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        l[x].push_back(y);
        h[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        cnt = 0;
        hdfs(i);

        if (cnt >= (n + 1) / 2)
        {
            ++result;
            continue;
        }

        memset(visited, false, sizeof(visited));
        cnt = 0;

        ldfs(i);

        if (cnt >= (n + 1) / 2)
        {
            ++result;
        }
    }

    cout << result << '\n';

    return 0;
}