#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 대소문자 변환 (toupper, tolower)

string solution(string s) {
    string answer = "";

    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            idx = 0;
            continue;
        }

        if (idx % 2 == 0) {
            s[i] = toupper(s[i]);
        } else {
            s[i] = tolower(s[i]);
        }
        idx++;
    }
    return s;
}