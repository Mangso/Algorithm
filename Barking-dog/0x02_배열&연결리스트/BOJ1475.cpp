#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    string str;
    cin >> str;

    int arr[10] = {0};

    for (int i = 0; i < str.size(); i++)
    {
        arr[str[i] - '0']++;
    }

    int num = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i != 9 && i != 6)
            num = max(num, arr[i]);
    }

    cout << max(num, (arr[6] + arr[9] + 1) / 2);
    return 0;
}

/* 다른풀이

int main()
{
    int N;
    cin >> N;
    if (N == 0)
    {
        cout << 1;
        return 0;
    }

    vector<int> arr(10, 0);

    while (N > 0)
    {
        int M = N % 10;

        if (M == 9)
        {
            arr[6] += 1;
        }
        else
            arr[M] += 1;

        N /= 10;
    }

    arr[6] = ceil(arr[6] / 2.0);

    cout << *max_element(arr.begin(), arr.end());
}

*/ 