#include <iostream>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    unordered_set<string> input_words;  //
    set<string> compound_words;         // 정렬 유지

    while (cin >> word) {
        input_words.insert(word);
    }

    for (const auto &i : input_words) {
        for (const auto &j : input_words) {
            if (i == j) continue;
            compound_words.insert(i + j);
            compound_words.insert(j + i);
        }
    }

    for (const auto &k : compound_words) {
        cout << k << endl;
    }

    return 0;
}
