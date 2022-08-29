#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool Check(string s) {
    for (auto ele : s) {
        if (!isalpha(ele)) return false;
    }
    return true;
}

int solution(string str1, string str2) {
    for (int i = 0; i < str1.size(); i++) str1[i] = toupper(str1[i]);
    for (int i = 0; i < str2.size(); i++) str2[i] = toupper(str2[i]);

    vector<string> v1, v2;
    for (int i = 0; i < (str1.size() - 1); i++) {
        string tmp = str1.substr(i, 2);
        if (Check(tmp)) v1.push_back(tmp);
    }

    for (int i = 0; i < (str2.size() - 1); i++) {
        string tmp = str2.substr(i, 2);
        if (Check(tmp)) v2.push_back(tmp);
    }
    if (v1.empty() && v2.empty()) return 65536;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<string> kyo, hab;
    kyo.resize(v1.size() + v2.size());
    hab.resize(v1.size() + v2.size());

    auto iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), kyo.begin());
    kyo.resize(iter - kyo.begin());
    auto iter2 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), hab.begin());
    hab.resize(iter2 - hab.begin());

    int answer = double(kyo.size()) / double(hab.size()) * 65536;

    return answer;
}