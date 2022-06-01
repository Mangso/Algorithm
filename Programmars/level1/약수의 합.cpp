#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int GetSum(int n) {
    vector<int> v;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != n / i) v.push_back(n / i);
        }
    }
    return std::accumulate(v.begin(), v.end(), 0);
}

int solution(int n) {
    int answer = GetSum(n);
    return answer;
}