// 회사 문화 1
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Person {
    int parent;
    int compliment = 0;
};

vector<Person> Workers(100001);
vector<int> dp(100001, -1);

int solve(int n) {
    if (n == -1) return 0;
    if (dp[n] != -1)
        return dp[n];
    else
        dp[n] = Workers[n].compliment;

    return dp[n] += solve(Workers[n].parent);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> Workers[i].parent;
    }

    for (int i = 0; i < m; i++) {
        int num_worker, c;
        cin >> num_worker >> c;
        Workers[num_worker].compliment += c;
    }

    for (int i = 1; i <= n; i++) {
        cout << solve(i) << ' ';
    }

    return 0;
}