// 분해합
// 브루트포스 알고리즘

#include <iostream>

using namespace std;

int main()
{
    int n, tmp;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        tmp = i;
        while (tmp)
        {
        sum += tmp % 10;
        tmp /= 10;
        }

        if (i + sum == n)
        {
        cout << i;
        return 0;
        }
    }
    cout << 0;
    return 0;
}