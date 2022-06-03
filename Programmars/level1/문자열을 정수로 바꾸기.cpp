#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> v;
    char sign = s[0];

    if (sign == '-' || sign == '+') {
        string tmp;
        tmp.assign(s.begin() + 1, s.end());
        if (sign == '-')
            answer = stoi(tmp) * -1;
        else
            answer = stoi(tmp);
    } else
        answer = stoi(s);
    return answer;
}

/* 다른 풀이
#include <string>
using namespace std;

int solution(string s) {
    int answer = 0;

    // c_str()로 char * 형태로 만든 후 atoi 함수 적용.
    // atoi는 음수의 경우 '-' 음수 부호로 해석해서 정상적인 반환이 이루어짐.

    answer = atoi(s.c_str());

    return answer;
}

*/
