#include <iostream>
#include <string>
#include <vector>

bool solution(int x) {
    int tmp = x;
    int sum = 0;
    while (tmp) {
        int num = tmp % 10;
        sum += num;
        tmp /= 10;
    }

    bool answer;
    if (x % sum == 0)
        answer = true;
    else
        answer = false;
    return answer;
}