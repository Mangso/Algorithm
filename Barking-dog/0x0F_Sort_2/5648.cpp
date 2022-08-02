// 역원소 정렬
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long Flip(string num) {
    long long flip_num = int(num[0] - '0');
    for (size_t i = 1; i < num.size(); i++) {
        flip_num += pow(10, i) * int(num[i] - '0');
    }
    return flip_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> v;
    string num;
    // for (int i = 0; i < n; i++) {
    //     cin >> num;
    //     long long flip_num = Flip(num);
    //     v.push_back(flip_num);
    // }

    for (int i = 0; i < n; i++) {
        cin >> num;
        reverse(num.begin(), num.end());
        v.push_back(stoll(num));
    }

    sort(v.begin(), v.end());

    for (const auto& ele : v) {
        cout << ele << '\n';
    }

    return 0;
}