// 카드 역배치

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main()
{
    vector<int> v;

    for(int i =1;i<21 ;i++)
    {
        v.push_back(i);
    }

    for(int i =0;i<10;i++)
    {
        int a, b;
        cin >> a >> b;

        reverse(v.begin() + (a-1), v.begin() + b);
        
    }

    for(auto element : v)
        cout << element << " ";


    return 0;
}