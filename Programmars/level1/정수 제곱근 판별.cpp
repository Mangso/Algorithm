#include <cmath>
#include <string>
#include <vector>

// sqrt 의 time complexty 는?

long long solution(long long n) {
    long long answer = 0;
    long long x = std::sqrt(n);
    if (x * x == n) {
        answer = (x + 1) * (x + 1);
    } else
        answer = -1;

    return answer;
}