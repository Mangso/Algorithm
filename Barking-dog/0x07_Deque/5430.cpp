// AC

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

void parse(string& arr, deque<int>& dq) {
    int cur = 0;
    for (int i = 1; i < arr.size() - 1; i++) {
        if (arr[i] == ',') {
            dq.push_back(cur);
            cur = 0;
        } else {
            cur = 10 * cur + (arr[i] - '0');
        }
    }

    if (cur != 0) {
        dq.push_back(cur);
    }
}
void print(deque<int>& dq) {
    cout << '[';
    for (size_t i = 0; i < dq.size(); i++) {
        cout << dq[i];
        if (i + 1 != dq.size()) {
            cout << ",";
        }
    }
    cout << "]\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        deque<int> dq;

        string tmp;
        cin >> tmp;
        parse(tmp, dq);

        int rev = 0;
        bool empty_flag = false;
        for (auto c : p) {
            if (c == 'R') {
                rev = 1 - rev;
            } else {
                if (dq.empty()) {
                    empty_flag = true;
                    break;
                }
                if (!rev)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        if (empty_flag)
            cout << "error\n";
        else {
            if (rev) reverse(dq.begin(), dq.end());
            print(dq);
        }
    }

    return 0;
}