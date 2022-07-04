#include <iostream>
#include <string>
using namespace std;

bool solution(string s) {
    bool answer = true;
    int p_cnt = 0;
    int y_cnt = 0;
    for (const auto &ele : s) {
        if (ele == 'p' || ele == 'P')
            p_cnt++;
        else if (ele == 'y' || ele == 'Y')
            y_cnt++;
    }

    if (p_cnt != y_cnt)
        answer = false;
    else
        answer = true;

    return answer;
}