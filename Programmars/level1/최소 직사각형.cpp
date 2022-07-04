#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0;
    int max_h = 0;
    for (auto ele : sizes) {
        if (ele[0] < ele[1]) {
            swap(ele[0], ele[1]);
        }
        max_w = max(max_w, ele[0]);
        max_h = max(max_h, ele[1]);
    }
    int answer = max_w * max_h;
    return answer;
}