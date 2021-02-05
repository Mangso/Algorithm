// 바이러스

#include <iostream>

using namespace std;

int arr[101][101];
int visit[101];
int nComputer;
int cnt(0);

void dfs(int n)
{
    cnt++;
    visit[n] = 1;
    for (int i = 1; i <= nComputer; i++)
    {
        if (arr[n][i] && !visit[i])
            dfs(i);
    }
}
int main()
{
    int n;
    cin >> nComputer >> n;

    while (n--)
    {

        int x, y;
        cin >> x >> y;
        // arr[x][y] = arr[y][x] = 1 로 쓸 수 있음.
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    dfs(1);

    cout << cnt -1 << '\n';
    return 0;
}