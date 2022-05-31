#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    auto min_idx = min_element(arr.begin(), arr.end()) - arr.begin();
    arr.erase(arr.begin() + min_idx);

    if (arr.empty()) arr.push_back(-1);

    return arr;
}