#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> v;
    for (auto num : numbers) {
        v.push_back(to_string(num));
    }

    sort(v.begin(), v.end(), comp);

    if (v[0].compare("0") == 0)
        return "0";

    for (auto ele : v) answer += ele;

    return answer;
}