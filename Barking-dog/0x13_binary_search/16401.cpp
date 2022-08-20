// 과자 나눠주기
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int M, N;
int snack[1000002];

bool Check(int x) {
    if (x == 0) return true;
    long long cnt = 0;

    for (int i = 0; i < N; i++) {
        cnt += snack[i] / x;
    }

    return cnt >= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> snack[i];
    }

    int start = 0;
    int end = *max_element(snack, snack + N);

    while (start < end) {
        int mid = (start + end + 1) / 2;

        if (Check(mid))
            start = mid;
        else
            end = mid - 1;
    }

    cout << start << '\n';

    return 0;
}