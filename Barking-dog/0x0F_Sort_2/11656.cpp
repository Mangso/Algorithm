// 접미사 배열
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    vector<string> words;
    for (size_t i = 0; i < S.size(); i++) {
        string tmp = S.substr(i);

        words.push_back(tmp);
    }

    sort(words.begin(), words.end());

    for (const auto& w : words) {
        cout << w << '\n';
    }

    return 0;
}