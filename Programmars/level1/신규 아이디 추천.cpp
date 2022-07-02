#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    // Step 1
    for (int i = 0; i < new_id.size(); ++i) {
        new_id[i] = tolower(new_id[i]);
    }

    // Step 2
    for (int i = 0; i < new_id.size(); ++i) {
        new_id = regex_replace(new_id, regex("[^a-z0-9-_.]+"), "");
    }

    // Step 3
    string tmp;
    for (char c : new_id) {
        if (c == '.' && tmp.back() == '.') continue;
        tmp += c;
    }
    new_id = tmp;

    // Step 4
    if (new_id.front() == '.') new_id.erase(0, 1);
    if (new_id.back() == '.') new_id.pop_back();

    // Step 5
    if (new_id.empty()) new_id += 'a';

    // Step 6
    if (new_id.size() >= 16) new_id.erase(15);
    if (new_id.back() == '.') new_id.pop_back();

    // Step 7
    if (new_id.size() <= 2) {
        char last_char = new_id.back();
        for (int i = 0; i <= 3 - new_id.size(); i++) {
            new_id += last_char;
        }
    }

    string answer = new_id;

    return answer;
}