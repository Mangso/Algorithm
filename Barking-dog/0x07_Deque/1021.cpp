// 회전하는 큐

#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    deque<int> dq;

    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    int count = 0;
    while (M--) {
        int num;
        cin >> num;

        int dq_size = int(dq.size());

        int idx;
        for (int i = 0; i < dq_size; i++) {
            if (dq[i] == num) {
                idx = i;
                break;
            }
        }

        if (idx < dq_size - idx) {
            while (true) {
                if (dq.front() == num) {
                    dq.pop_front();
                    break;
                }

                ++count;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            while (true) {
                if (dq.front() == num) {
                    dq.pop_front();
                    break;
                }
                ++count;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << count;
    return 0;
}