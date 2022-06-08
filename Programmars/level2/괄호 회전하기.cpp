#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// 올바른 괄호 체크 하는 함수.
bool Check(const std::string& s) {
    std::stack<char> st;

    for (auto& c : s) {
        if (c == '{' || c == '(' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;

            auto top = st.top();
            if ((top == '{' && c == '}') || (top == '(' && c == ')') || (top == '[' && c == ']')) {
                st.pop();
            }
        }
    }

    return st.empty();
}
int solution(string s) {
    string res = s;
    int cnt = 0;
    // 한칸 씩 왼쪽으로 밀기
    for (int i = 0; i < s.size(); i++) {
        char tmp = res[0];
        res.erase(0, 1);
        res.push_back(tmp);

        if (Check(res) == true) cnt++;
    }

    return cnt;
}