#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& numbers, int& target, int& answer, int sum, int index) {
    // 가장 깊은 깊이 찍었을 때
    if (index == numbers.size()) {
        if (sum == target) {
            answer++;
        }

        return;
    }

    dfs(numbers, target, answer, sum + numbers[index], index + 1);
    dfs(numbers, target, answer, sum - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(numbers, target, answer, 0, 0);
    return answer;
}