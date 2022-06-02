#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int One(vector<int>& answers) {
    int cnt = 0;
    int arr[5] = {1, 2, 3, 4, 5};

    int i = 0;
    for (auto ele : answers) {
        if (i % 5 == 0) i = i % 5;

        if (arr[i] == ele) cnt++;
        i++;
    }
    return cnt;
}

int Two(vector<int>& answers) {
    int arr[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int cnt = 0;
    int i = 0;

    for (auto ele : answers) {
        if (i % 8 == 0) i = i % 8;

        if (arr[i] == ele) cnt++;
        i++;
    }
    return cnt;
}

int Three(vector<int>& answers) {
    int arr[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int cnt = 0;
    int i = 0;
    for (auto ele : answers) {
        if (i % 10 == 0) i = i % 10;

        if (arr[i] == ele) cnt++;
        i++;
    }
    return cnt;
}

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}
vector<int> solution(vector<int> answers) {
    vector<pair<int, int>> v;
    vector<int> answer;

    v.push_back({1, One(answers)});
    v.push_back({2, Two(answers)});
    v.push_back({3, Three(answers)});

    sort(v.begin(), v.end(), comp);

    answer.push_back(v[0].first);
    for (int i = 1; i < v.size(); i++) {
        if (v[0].second != v[i].second) break;
        answer.push_back(v[i].first);
    }
    return answer;
}