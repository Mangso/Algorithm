// 정수 제곱근
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    long long num = static_cast<long long>(sqrt(n));

    if (num * num < n) num += 1;

    cout << num;

    return 0;
}