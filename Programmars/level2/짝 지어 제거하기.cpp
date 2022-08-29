#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solution(string s) {
    int answer = 0;

    stack<char> st;

    for (auto ele : s) {
        if (st.empty()) {
            st.push(ele);
            continue;
        }

        if (st.top() == ele) {
            st.pop();
        } else {
            st.push(ele);
        }
    }

    if (st.empty()) answer = 1;

    return answer;
}