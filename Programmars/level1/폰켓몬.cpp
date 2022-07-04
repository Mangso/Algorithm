#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
    int answer;
    set<int> s;
    int n = nums.size() / 2;

    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }

    if (s.size() <= n)
        answer = s.size();
    else
        answer = n;

    return answer;
}