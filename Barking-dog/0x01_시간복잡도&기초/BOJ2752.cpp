// 세 수 정렬

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;

    for (int i= 0 ; i <3 ;i++){
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(),v.end());

    for (auto element : v)
        cout << element << " ";

    return 0;
}