// 돌 게임

#include <iostream>

using namespace std;

int dp[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
    }

    if (dp[n] % 2 == 0)
        cout << "CY";
    else
        cout << "SK";

    return 0;
}