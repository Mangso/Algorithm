// 연속 합

#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];
int arr[100001];
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    int max_result = dp[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i-1] +arr[i], arr[i]);
        max_result = max(max_result,dp[i]);
    }

    cout << max_result;

    return 0;
}