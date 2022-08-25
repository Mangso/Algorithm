// 좋은 단어
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        stack<char> st;
        for (auto ele : s) {
            if (st.empty()) {
                st.push(ele);
            } else {
                if (st.top() == ele)
                    st.pop();
                else
                    st.push(ele);
            }
        }
        if (st.empty()) cnt++;
    }

    cout << cnt;
    return 0;
}