// N- Queen
#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt = 0;

vector<int> visited(15);

bool Check(int cur) {
    for (int i = 0; i < cur; i++) {
        if (visited[cur] == visited[i] || cur - i == abs(visited[cur] - visited[i])) {
            return false;
        }
    }

    return true;
}

void func(int cur) {
    if (cur == N) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        visited[cur] = i;

        if (Check(cur))
            func(cur + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    func(0);
    cout << cnt;

    return 0;
}