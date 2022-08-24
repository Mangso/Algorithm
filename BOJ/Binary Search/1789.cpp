// 수들의 합
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long S;
    cin >> S;

    long long sum = 0;
    int i = 1;
    while (S >= sum) {
        sum += i;
        // cout << sum << " " << i << '\n';
        i++;
    }

    cout << i - 2;

    return 0;
}