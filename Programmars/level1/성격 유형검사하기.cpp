#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int score(int choice) {
    if (choice == 1 || choice == 7) return 3;
    if (choice == 2 || choice == 6) return 2;
    if (choice == 3 || choice == 5) return 1;

    return 0;
}

void makeMap(map<char, int>& m) {
    vector<char> v = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    for (const auto& ele : v) {
        m[ele] = 0;
    }
}


string solution(vector<string> survey, vector<int> choices) {
    /*
        survey : AN CF MJ RT NA
        choice : 7 1 3
    */
    vector<char> v = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};

    map<char, int> m;
    makeMap(m);

    for (int i = 0; i < survey.size(); i++) {
        auto s = survey[i];
        if (choices[i] > 4) {
            m[s[1]] += score(choices[i]);
        } else if (choices[i] < 4) {
            m[s[0]] += score(choices[i]);
        }
    }

    vector<pair<char, int>> result;

    for (auto ele : v) {
        result.push_back({ele, m[ele]});
    }

    string answer = "";
    for (int i = 0; i < result.size(); i += 2) {
        if (result[i].second < result[i + 1].second) {
            answer += result[i + 1].first;
        } else if (result[i].second > result[i + 1].second) {
            answer += result[i].first;
        } else {
            if (result[i].first > result[i + 1].first)
                answer += result[i].first;
            else
                answer += result[i].first;
        }
    }

    return answer;
}
