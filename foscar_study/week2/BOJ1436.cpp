// 영화감독 숌
// 브루트포스 알고리즘

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt_flag = 0;

    for (int i = 0;; i++)
    {

        int num = i;
        int cnt = 0;

        while (num > 0)
        {
            int tmp = num % 1000;

            if (tmp == 666)
            cnt = 1;

            num = num / 10;
        }

        if (cnt == 1)
        {
            cnt_flag++;
        }

        if (cnt_flag == n)
        {
            cout << i;
            break;
        }
    }

    return 0;
}