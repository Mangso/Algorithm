// 블랙잭
// 브루트포스 알고리즘

#include <iostream>

using namespace std;

int arr[101];

int main()
{
    int n, m;
    cin >> n >> m;

    int max = 0;

    for (int i = 0; i < n; i++)
    {
        int n;
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
        for (int k = j + 1; k < n; k++)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum <= m && max < sum)
            max = sum;
        }
        }
    }

    cout << max << '\n';

    return 0;
}