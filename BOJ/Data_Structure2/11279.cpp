// 최대 힙
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, less<int>> pq;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x != 0) {
            pq.push(x);
        } else {
            if (pq.empty()) {
                cout << 0 << '\n';
                continue;
            }

            cout << pq.top() << '\n';
            pq.pop();
        }
    }

    return 0;
}