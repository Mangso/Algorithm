#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }

    int answer = std::accumulate(v.begin(), v.end(), 0);

    return answer;
}