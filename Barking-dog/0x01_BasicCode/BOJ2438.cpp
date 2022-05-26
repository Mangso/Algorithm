// 별 찍기 - 1

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << '\n';
    }

    return 0;
}