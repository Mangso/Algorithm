// 스택 수열

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    cin >> n;

    stack<int> st;
    vector<int> v;
    vector<char> c_vec;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        st.push(i);
        c_vec.push_back('+');

        while (!st.empty()) {
            if (v[idx] == st.top()) {
                st.pop();
                c_vec.push_back('-');
                idx++;
            } else
                break;
        }
    }

    if (st.empty()) {
        for (auto& ele : c_vec)
            cout << ele << '\n';
    } else
        cout << "NO" << '\n';

    return 0;
}