// 5014 스타트링크
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dist[1000002];
int Visited[1000002];

int F, S, G, U, D;

void BFS(int s) {
    queue<int> Q;
    Q.push(s);
    Visited[s] = 1;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (auto ele : {U, D}) {
            int new_pose;
            if (ele == U)
                new_pose = cur + ele;
            else
                new_pose = cur - ele;

            if (new_pose < 1 || new_pose > F) continue;
            if (Visited[new_pose] == 1) continue;

            Visited[new_pose] = 1;
            dist[new_pose] = dist[cur] + 1;
            Q.push(new_pose);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> F >> S >> G >> U >> D;

    BFS(S);
    if (Visited[G] == 0)
        cout << "use the stairs";
    else
        cout << dist[G];
}