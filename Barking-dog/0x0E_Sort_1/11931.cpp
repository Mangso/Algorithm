// 수 정렬하기 4
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Compare(const int &a, const int &b) {
    return a > b ? true : false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), Compare);

    for (auto ele : v) {
        cout << ele << '\n';
    }

    return 0;
}