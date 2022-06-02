#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (auto &ele : arr) {
        if (ele % divisor == 0) answer.push_back(ele);
    }
    if (answer.empty()) answer.push_back(-1);

    sort(answer.begin(), answer.end());

    return answer;
}