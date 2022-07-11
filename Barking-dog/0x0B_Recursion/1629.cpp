// 곱셈
#include <iostream>

using namespace std;

long long POW(long long a, long long b, long long c) {
    if (b == 1)
        return a % c;

    long long result = POW(a, b / 2, c);
    result = (result * result) % c;

    if (b % 2 == 0) return result;

    return (result * a) % c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << POW(a, b, c);
    return 0;
}