#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v1, v2;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v1.push_back(n);
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        v2.push_back(n);
    }

    sort(v1.begin(), v1.end());

    for (const auto& ele : v2) {
        int find = binary_search(v1.begin(), v1.end(), ele);
        cout << find << '\n';
    }

    return 0;
}