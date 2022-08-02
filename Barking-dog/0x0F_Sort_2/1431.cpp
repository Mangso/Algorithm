// 시리얼 번호
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Compare(const string& a, const string& b) {
    int a_len = int(a.length());
    int b_len = int(b.length());

    if (a_len != b_len) {
        return a_len < b_len;
    } else if (a_len == b_len) {
        int a_sum = 0;
        int b_sum = 0;
        for (const auto& c : a) {
            if (isdigit(c) == 1)
                a_sum += int(c - '0');
        }

        for (const auto& c : b) {
            if (isdigit(c) == 1)
                b_sum += int(c - '0');
        }

        if (a_sum != b_sum)
            return a_sum < b_sum;
    }

    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<string> serials(N);
    for (int i = 0; i < N; i++) {
        cin >> serials[i];
    }

    sort(serials.begin(), serials.end(), Compare);

    for (const auto& serial : serials) {
        cout << serial << '\n';
    }

    return 0;
}