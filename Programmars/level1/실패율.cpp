#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CountNum(vector<int>& stages, int num) {
    int count = 0;
    for (const auto& ele : stages) {
        if (ele == num) count++;
    }
    return count;
}

int ArriveNum(vector<int>& stages, int num) {
    int count = 0;
    for (const auto& ele : stages) {
        if (ele >= num) count++;
    }
    return count;
}

bool comp(const pair<int, double>& l, const pair<int, double>& r) {
    if (l.second == r.second)
        return l.first < r.first;
    return l.second > r.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<pair<int, double>> failures;

    std::sort(stages.begin(), stages.end());
    int not_clear = 0;
    for (int i = 0; i < N; i++) {
        int not_clear = CountNum(stages, i + 1);
        int arrive = ArriveNum(stages, i + 1);
        double failure = double(not_clear) / double(arrive);
        failures.push_back({i + 1, failure});
    }

    stable_sort(failures.begin(), failures.end(), comp);
    vector<int> answer;

    for (int i = 0; i < N; i++) {
        answer.push_back(failures[i].first);
    }
    return answer;
}