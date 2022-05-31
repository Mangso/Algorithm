#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = 1; j < numbers.size(); j++) {
            if (i != j) {
                int result = numbers[i] + numbers[j];
                answer.push_back(result);
            }
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}