// 문자열 집합
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_set<string> us;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        us.insert(s);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (us.find(s) != us.end())
            cnt++;
    }

    cout << cnt;
    return 0;
}