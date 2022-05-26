// 별 찍기 - 2
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (j <= t - i)
                cout << " ";
            else
                cout << "*";
        }
        cout << '\n';
    }

    return 0;
}