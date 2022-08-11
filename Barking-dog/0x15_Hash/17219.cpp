// 비밀번호 찾기
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> um;
    for (int i = 0; i < N; i++) {
        string url, passwd;
        cin >> url >> passwd;
        um.insert({url, passwd});
    }

    for (int i = 0; i < M; i++) {
        string url;
        cin >> url;
        cout << um[url] << '\n';
    }

    return 0;
}