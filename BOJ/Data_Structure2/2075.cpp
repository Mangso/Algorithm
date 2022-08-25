// N번째 큰 수
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    // 우선순위 큐 사이즈를 줄여주여야 함.
    for (int i = 0; i < N * N; i++) {
        int num;
        cin >> num;
        if (pq.size() < N) {
            pq.push(num);
        } else if (pq.top() < num) {
            pq.push(num);
            pq.pop();
        }
    }

    cout << pq.top();
    return 0;
}