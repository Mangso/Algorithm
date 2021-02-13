// 숫자판 점프
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// set 중복제거용.
set<int> result;
int board[5][5];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int cnt, int x, int y, int num)
{
    // 사이즈 6되면 넣고 dfs 리턴.
    if (cnt == 6)
    {
        result.insert(num);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            continue;
        dfs(cnt + 1, nx, ny, num * 10 + board[nx][ny]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    // dfs 시작점을 모든 좌표로.
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            dfs(1, i, j, board[i][j]);

    cout << result.size() << '\n';

    return 0;
}