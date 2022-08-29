#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> dq;

    for (int i = 0; i < speeds.size(); i++) {
        int day = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) day++;
        dq.push_back(day);
    }

    int base = dq.front();
    dq.pop_front();
    int cnt = 1;
    while (!dq.empty()) {
        auto r = dq.front();

        if (base >= r) {
            cnt++;
            dq.pop_front();
        } else {
            answer.push_back(cnt);
            base = r;
            cnt = 1;
            dq.pop_front();
        }
    }
    answer.push_back(cnt);
    for (auto ele : answer) cout << ele << ' ';
    return answer;
}