#include <iostream>
#include <string>
#include <vector>

std::vector<long long> solution(int x, int n) {
    std::vector<long long> answer;

    for (int i = 0; i < n; i++) {
        long long num = x * (i + 1);
        answer.push_back(num);
    }

    return answer;
}