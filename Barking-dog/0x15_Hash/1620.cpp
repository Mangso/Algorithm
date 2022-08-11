// 나는야 포켓몬 마스터 이다솜
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> um1;
    unordered_map<int, string> um2;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        um1.insert({s, i});
        um2.insert({i, s});
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9') {
            cout << um2[stoi(s)] << '\n';
        } else
            cout << um1[s] << '\n';
    }

    return 0;
}