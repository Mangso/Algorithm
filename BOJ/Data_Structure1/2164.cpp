// 카드 2
#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    deque<int> dq(N);
    iota(dq.begin(), dq.end(), 1);

    while (dq.size() > 1) {
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }

    cout << dq.front();

    return 0;
}