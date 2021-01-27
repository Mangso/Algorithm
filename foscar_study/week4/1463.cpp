// 1로 만들기

#include <iostream>
#include <algorithm>

using namespace std;

//10^6
int dp[1000001];

// int min(int a, int b)
// {
//     return a > b ? b : a;
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);

        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);

        // cout << i << " " << dp[i] <<'\n';
    }

    cout << dp[n];

    return 0;
}