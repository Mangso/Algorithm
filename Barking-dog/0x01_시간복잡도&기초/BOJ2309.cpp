// 일곱난쟁이

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t = 9;
    int sum = 0;
    vector<int> v(9);

    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());

    int p, q;

    for (p = 0; p < 9; p++)
    {
        for (q = p + 1; q < 9; q++)
        {
            if (sum - (v[p] + v[q]) == 100)
            {
                for (int i = 0; i < 9; i++)
                {
                    if (i == p || i == q)
                        continue;
                    else
                        cout << v[i] << '\n';
                }
                return 0;
            }
        }
    }

    return 0;
}

    /* 틀린 풀이
    틀린 이유 :2개를 빼서 합이 100이 되는 모든 쌍을 찾으면 안 되고,
    한 쌍을 찾는 순간 끝내야 합니다. 
    그런 쌍이 여러 개 있을 때 모두를 지워버리면 당연히 안 됨.
    여러가지 경우가 나올수 있으므로 그냥 for 문안에서 끝내는 거로.

    for (p = 0; p < 9; p++)
    {
        for (q = p + 1; q < 9; q++)
        {
            if (sum - (v[p] + v[q]) == 100)
            {
                v[p] = -1;
                v[q] = -1;
                break;
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 2; i <9 ; i++)
    {
        cout << v[i] << '\n';
    }
    return 0;
    */
