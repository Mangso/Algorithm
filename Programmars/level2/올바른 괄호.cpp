#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;

    stack<char> st;

    for (auto ele : s) {
        if (st.empty() || ele == '(') {
            st.push(ele);
            continue;
        }

        auto top = st.top();
        if (top == '(' && ele == ')') {
            st.pop();
        }
    }

    if (!st.empty()) answer = false;

    return answer;
}