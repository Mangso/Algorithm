#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factor(int a) {
    int cnt = 0;
    for (int i = 1; i <= a / 2; i++) {
        if (a % i == 0) {
            cnt += 1;
        }
    }
    cnt += 1;

    if (cnt % 2 == 0) return 1;

    return 0;
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (factor(i) == 1)
            answer += i;
        else
            answer -= i;
    }

    return answer;
}