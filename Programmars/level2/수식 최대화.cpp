#include <bits/stdc++.h>

#include <string>
#include <vector>

using namespace std;

vector<string> MakeComb(string str) {
    vector<string> v;
    sort(str.begin(), str.end());
    do {
        string tmp;
        for (auto ele : str) {
            tmp += ele;
        }
        v.push_back(tmp);

    } while (next_permutation(str.begin(), str.end()));

    return v;
}

long long Calculate(long long a, long long b, char op) {
    if (op == '*') return a * b;
    if (op == '-') return a - b;
    if (op == '+') return a + b;
}

long long solution(string expression) {
    long long answer = -1;

    // Step 1 : 피연산자 벡터, 연산자 벡터 나누기
    vector<long long> vec_operands;
    vector<char> vec_operators;
    unordered_set<char> us;
    string tmp;

    for (const auto& e : expression) {
        if (!isdigit(e)) {
            vec_operands.push_back(stoll(tmp));
            vec_operators.push_back(e);
            us.insert(e);
            tmp.clear();
            continue;
        }

        tmp += e;
    }
    vec_operands.push_back(stoll(tmp));

    string operators(us.begin(), us.end());
    vector<string> comb = MakeComb(operators);

    for (auto ele : comb) {
        vector<long long> tmp_operands = vec_operands;
        vector<char> tmp_operators = vec_operators;
        for (int i = 0; i < ele.size(); i++) {
            for (int j = 0; j < tmp_operators.size();) {
                if (ele[i] == tmp_operators[j]) {
                    long long res = Calculate(tmp_operands[j], tmp_operands[j + 1], ele[i]);

                    tmp_operands.erase(tmp_operands.begin() + j);
                    tmp_operands.erase(tmp_operands.begin() + j);
                    tmp_operands.insert(tmp_operands.begin() + j, res);

                    tmp_operators.erase(tmp_operators.begin() + j);
                } else
                    j++;
            }
        }

        answer = max(answer, abs(tmp_operands[0]));
    }

    return answer;
}