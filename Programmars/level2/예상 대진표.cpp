#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 1;
    while (n) {
        if (a % 2 != 0) a += 1;
        if (b % 2 != 0) b += 1;

        if (a == b) break;

        a /= 2;
        b /= 2;

        n /= 2;

        answer++;
    }

    return answer;
}