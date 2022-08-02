// 단어 정렬
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Compare(const string& a, const string& b) {
    if (a.length() == b.length()) {
        return a < b;
    }

    return a.length() < b.length();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    string str;
    vector<string> words;
    for (int i = 0; i < N; i++) {
        cin >> str;
        words.push_back(str);
    }

    sort(words.begin(), words.end(), Compare);
    words.erase(unique(words.begin(), words.end()), words.end());

    for (const auto& w : words) {
        cout << w << '\n';
    }
    return 0;
}