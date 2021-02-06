// 섬의 개수

#include <iostream>
using namespace std;

int w, h;
int arr[51][51];
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int cnt;

void dfs(int x, int y)
{
    arr[x][y] = 2;

    for (int i = 0; i < 8; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (0 <= cx && 0 <= cy && cx < 50 && cy < 50)
        {
            if (arr[cx][cy] == 1)
                dfs(cx, cy);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        cin >> h >> w;

        if (w == 0 && h == 0)
        {
            break;
        }
        cnt = 0;
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
                cin >> arr[i][j];

        for (int i = 0; i < w; ++i)
        {
            for (int j = 0; j < h; ++j)
            {
                if (arr[i][j] == 1)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}