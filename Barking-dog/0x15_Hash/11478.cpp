// 서로 다른 부분 문자열의 개수
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    int size = int(S.size());

    unordered_set<string> us;
    for (int i = 0; i < size; i++) {
        string s;
        for (int j = i; j < size; j++) {
            s += S[j];
            us.insert(s);
        }
    }

    cout << us.size();

    return 0;
}