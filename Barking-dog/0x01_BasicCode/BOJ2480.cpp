// 주사위 세개
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> v;
    int cnt = 1;
    for(int i =0;i<3;i++){
        int num;
        cin >> num;
    
        v.push_back(num);
    }

    if(v[0] == v[1] && v[0] == v[2]){
        cout << 10000 + v[0] * 1000;
    }
    else if(v[0] == v[1] || v[0] == v[2]){
        cout << 1000 + v[0] * 100;
    }
    else if (v[1] == v[2]){
        cout << 1000 + v[1] * 100;
    }
    else {
        cout << *max_element(v.begin(),v.end()) * 100;
    }

    return 0;
}