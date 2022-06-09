// 옥상 정원
// monotone stack (단조 수열)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, height;
    cin >> n;
    vector<long long> buildings;
    stack<long long> st;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> height;
        buildings.push_back(height);

        while (!st.empty() && st.top() <= buildings[i]) {
            st.pop();
        }

        st.push(height);
        sum = sum + st.size() - 1;
    }

    cout << sum << '\n';
    return 0;
}