#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> players;

    for (auto ele : participant) {
        players[ele] += 1;
    }

    for (auto complete : completion) {
        players[complete] -= 1;
    }

    for (auto answer : players) {
        if (answer.second == 1) return answer.first;
    }
}