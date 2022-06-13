#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dist[100002];

int main() {
    int n, k;
    cin >> n >> k;

    fill(dist, dist + 100001, -1);
    dist[n] = 0;

    queue<int> q;
    q.push(n);

    while (dist[k] == -1) {
        auto cur = q.front();
        q.pop();

        for (auto ele : {cur - 1, cur + 1, 2 * cur}) {
            if (ele < 0 || ele > 100000) continue;
            if (dist[ele] != -1) continue;
            dist[ele] = dist[cur] + 1;
            q.push(ele);
        }
    }

    cout << dist[k];
}