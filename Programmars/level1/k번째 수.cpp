#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        vector<int> v;
        v.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);

        std::sort(v.begin(), v.end());
        answer.push_back(v[commands[i][2] - 1]);
    }

    return answer;
}