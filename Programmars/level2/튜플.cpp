#include <bits/stdc++.h>

#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;

    string num;
    stack<char> st;
    vector<vector<int>> result;
    vector<int> tmp;
    for (int i = 1; i < s.size() - 1; i++) {
        if (st.empty() && s[i] == '{') {
            st.push(s[i]);
            continue;
        } else if (st.empty() && s[i] == ',') {
            continue;
        }

        if (isdigit(s[i])) {
            num += s[i];
            continue;
        }

        if (s[i] == ',') {
            tmp.push_back(stoi(num));
            num.clear();
        } else if (s[i] == '}') {
            tmp.push_back(stoi(num));
            result.push_back(tmp);
            st.pop();
            num.clear();
            tmp.clear();
        }
    }

    answer.resize(result.size());
    sort(result.begin(), result.end(), cmp);

    set<int> isused;

    int idx = 0;
    for (auto ele : result) {
        for (int i = 0; i < int(ele.size()); i++) {
            if (isused.find(ele[i]) == isused.end()) {
                isused.insert(ele[i]);
                answer[idx++] = ele[i];
            }
        }
    }

    return answer;
}
