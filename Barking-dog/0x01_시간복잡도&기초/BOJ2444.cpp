// 별 찍기 - 7 
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 위 세모
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * n - 1 - 2 * i; k++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}