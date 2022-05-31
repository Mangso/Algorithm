#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long tmp = n;

    vector<int> v;
    while (tmp) {
        int num = tmp % 10;
        tmp /= 10;
        v.push_back(num);
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (i == 0)
            answer += v[i];
        else
            answer += v[i] * pow(10, i);
    }

    return answer;
}