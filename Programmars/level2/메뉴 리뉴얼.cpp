#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void MakeComb(map<string, int>& comb, const string& order, vector<int>& course) {
    for (const auto& c : course) {
        if (c > order.size()) continue;

        vector<bool> temp(order.size(), true);
        for (int i = 0; i < c; i++) {
            temp[i] = false;
        }

        do {
            string s = "";
            for (int i = 0; i < order.size(); i++) {
                if (!temp[i]) s += order[i];
            }
            comb[s]++;
        } while (next_permutation(temp.begin(), temp.end()));
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> comb;

    for (auto order : orders) {
        sort(order.begin(), order.end());
        MakeComb(comb, order, course);
    }

    for (const auto& c : course) {
        int max_ = -1;
        for (const auto& ele : comb) {
            if (ele.second > 1 && c == ele.first.size()) {
                max_ = max(max_, ele.second);
            }
        }

        if (max_ > 1) {
            for (const auto& ele : comb) {
                if (c == ele.first.size() && ele.second == max_) {
                    answer.push_back(ele.first);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}