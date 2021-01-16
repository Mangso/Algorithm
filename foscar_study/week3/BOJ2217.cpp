// 로프
// Greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(std::vector<int>& lope){
    int max_result = 0;
    int idx = 0;
    for(int i=lope.size(); i>0;i--){
        max_result = max(max_result,(i)*lope[idx++]);
    }
    cout << max_result;
}
int main(){
    int n;
    cin >> n;

    vector<int> lope;

    for(int i=0 ;i < n; i++) {
        int num;
        cin >> num;
        lope.push_back(num);
    }

    sort(lope.begin(),lope.end());

    solve(lope);

    return 0;
}