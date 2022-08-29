#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<pair<string, string>> v;
    unordered_map<string, string> um;

    for (auto r : record) {
        string s1, s2, s3;
        stringstream tmp(r);
        tmp >> s1 >> s2 >> s3;

        if (s1 == "Enter") {
            um[s2] = s3;
            v.push_back({s1, s2});
        } else if (s1 == "Leave") {
            v.push_back({s1, s2});
        } else {
            um[s2] = s3;
        }
    }

    for (auto ele : v) {
        string post;
        if (ele.first == "Enter") {
            post = "님이 들어왔습니다.";
        } else {
            post = "님이 나갔습니다.";
        }
        answer.push_back(um[ele.second] + post);
    }

    return answer;
}