// 개수 세기
#include <iostream>
#include <array>

using namespace std;

int main()
{
    int n;
    cin >> n;

    array<int, 101> arr;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int v, cnt = 0;
    cin >> v;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == v)
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}