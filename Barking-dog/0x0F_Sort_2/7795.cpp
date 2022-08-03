// 먹을 것인가 먹힐 것인가
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    // A가 B보다 큰 쌍. A 만 확인.
    // upper_bound로 인덱스로 조작하기 ㅎㅎ.
    vector<int> A;
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            int n;
            cin >> n;
            A.push_back(n);
        }

        sort(A.begin(), A.end());

        int cnt = 0;
        for (int i = 0; i < M; i++) {
            int b;
            cin >> b;

            int index = upper_bound(A.begin(), A.begin() + N, b) - A.begin();
            cnt += N - index;
        }

        cout << cnt << '\n';

        A.clear();
    }

    return 0;
}