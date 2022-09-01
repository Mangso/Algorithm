// 암호 만들기
#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<char> password(15);
vector<char> V;
vector<bool> isused(15, false);

vector<char> Vowels{'a', 'e', 'i', 'o', 'u'};

bool check(char t) {
    if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
        return true;
    return false;
}

void func(int depth, int start, char prev) {
    if (depth == L) {
        int vowel = 0;
        int cons = 0;
        for (int i = 0; i < L; i++) {
            if (check(password[i]))
                vowel++;
            else
                cons++;
        }

        if (vowel >= 1 && cons >= 2) {
            for (int i = 0; i < L; i++) {
                cout << password[i];
            }
            cout << '\n';
        }
    }

    for (int i = start; i < C; i++) {
        if (prev < V[i] && !isused[i]) {
            isused[i] = true;
            password[depth] = V[i];
            func(depth + 1, start + 1, V[i]);
            isused[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        char c;
        cin >> c;
        V.push_back(c);
    }

    sort(V.begin(), V.end());
    func(0, 0, 0);

    return 0;
}