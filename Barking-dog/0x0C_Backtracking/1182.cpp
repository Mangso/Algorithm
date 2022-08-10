// 부분 수열의 합
#include <iostream>
#include <vector>

using namespace std;

int N, S;
int cnt = 0;
vector<int> V;
void func(int cur, int total) {
    if (cur == N) {
        if (total == S) cnt++;
        return;
    }

    func(cur + 1, total);
    func(cur + 1, total + V[cur]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        V.push_back(num);
    }

    func(0, 0);
    if (S == 0) cnt--;

    cout << cnt;
    return 0;
}