// ATM
// Greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>& nTime){
    int sum = 0;
    
    for(int i=0;i<nTime.size();i++){
        int sum_tmp = 0;
        for(int j= 0 ; j < i + 1 ; j++ ){
            sum_tmp = sum_tmp + nTime[j];
        }
        sum = sum + sum_tmp;
    }
    cout << sum;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> nTime;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        nTime.push_back(num);
    }

    sort(nTime.begin(),nTime.end());

    solve(nTime);

    return 0;

}