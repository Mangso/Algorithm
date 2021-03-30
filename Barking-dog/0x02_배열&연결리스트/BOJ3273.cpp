// 두 수의 합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int x;
    cin >> x;

    // 오름차순 정렬
    sort(v.begin(), v.end());

    int start = 0;
    int end = n - 1;

    int nCnt=0;
    
    while(start < end)
    {
        // 두 수의 합 같으면 앞,뒤 포인터 둘다 감소 및 cnt 증가.
        if(v[start] + v[end] == x)
        {
            nCnt++;
            start++;
            end--;
        }
        // 두 수의 합이 x 보다 큰 경우 뒤의 포인터 감소.
        else if (v[start] + v[end] > x)
        {
            end--;
        }
        // 작은 경우 앞 포인터 증가.
        else{
            start++;
        }
    }

    cout << nCnt;
    
    return 0;
}