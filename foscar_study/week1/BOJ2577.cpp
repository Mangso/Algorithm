// 숫자의 개수
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    int num;
    int k;
    int arr[10] = {
        0,
    };
    cin >> a >> b >> c;
    num = a * b * c;
    while (num)
    {
        k = num % 10;
        for (int i = 0; i < 10; i++)
        {
        if (k == i)
        {
            arr[i]++;
        }
        }
        num = num / 10;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        cout << arr[i] << '\n';
        else
        cout << arr[i] << '\n';
    }

    return 0;
}