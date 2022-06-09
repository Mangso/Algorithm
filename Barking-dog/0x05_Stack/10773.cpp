// 제로
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;

    stack<int> st;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        if (n != 0)
            st.push(n);
        else {
            st.pop();
        }
    }

    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    cout << sum << '\n';

    return 0;
}