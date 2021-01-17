// 최댓값

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int t = 9;
    int max_result =0;
    int idx= 0;

    vector<int> v;

    while(t--)
    {
        int num;
        cin >> num;

        v.push_back(num);
    }

    // vector 에서 최댓값 찾기.
    max_result = *max_element(v.begin(), v.end());
    // 최댓값 가지고 있는 index 찾기.
    idx = find(v.begin(),v.end(), max_result) - v.begin() + 1;
    
    cout << max_result << '\n';
    cout << idx << '\n';
    

    return 0;
}

/* 이게 더 좋은 풀이 같음.

int main()
{
    int arr[100];
    int max =0;
    int cnt =0;

    for(int i =1;i<10;i++)
    {
        cin >> arr[i];
        if(Max < arr[i])
        {
            Max = arr[i];
            cnt = i;
        }
    }
    cout << Max << '\n';
    cout << cnt;
    
    return 0;
}
*/ 