// 연산자 끼워넣기
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

vector<int> nums(12);
vector<int> operators;
int N;
int PLUS, MINUS, MULTI, MOD;
int cnt;

long long max_result = numeric_limits<long long>::min();
long long min_result = numeric_limits<long long>::max();

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    cin >> PLUS >> MINUS >> MULTI >> MOD;

    for (int i = 0; i < PLUS; i++) {
        operators.push_back(0);
    }
    for (int i = 0; i < MINUS; i++) {
        operators.push_back(1);
    }
    for (int i = 0; i < MULTI; i++) {
        operators.push_back(2);
    }
    for (int i = 0; i < MOD; i++) {
        operators.push_back(3);
    }
}

void Solve() {
    do {
        long long sum = nums[0];
        for (int i = 0; i < operators.size(); i++) {
            if (operators[i] == 0) {
                sum += nums[i + 1];
            } else if (operators[i] == 1) {
                sum -= nums[i + 1];
            } else if (operators[i] == 2) {
                sum *= nums[i + 1];
            } else if (operators[i] == 3) {
                sum /= nums[i + 1];
            }
        }
        max_result = max(sum, max_result);
        min_result = min(sum, min_result);
    } while (next_permutation(operators.begin(), operators.end()));

    cout << max_result << '\n';
    cout << min_result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();
    return 0;
}