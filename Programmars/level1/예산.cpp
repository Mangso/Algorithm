#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    int value = 0;
    int i = 0;
    while (i < d.size() && value + d[i] <= budget) {
        // 합계 업데이트
        value += d[i];
        i++;
        // 횟수 업데이트
        answer++;
    }
    return answer;
}