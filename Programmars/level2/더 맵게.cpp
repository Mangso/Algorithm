#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto& ele : scoville)
        pq.push(ele);

    while (pq.top() <= K) {
        if (pq.empty()) break;

        auto lowest = pq.top();
        pq.pop();

        if (pq.empty()) break;

        auto second = pq.top();
        pq.pop();

        auto mix = lowest + second * 2;
        pq.push(mix);
        answer++;
    }

    if (pq.empty()) answer = -1;
    return answer;
}