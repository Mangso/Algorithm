// 차집합
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_set<int> A, B;

    int n_a, n_b;
    cin >> n_a >> n_b;

    for (int i = 0; i < n_a; i++) {
        int num;
        cin >> num;
        A.insert(num);
    }

    for (int i = 0; i < n_b; i++) {
        int num;
        cin >> num;
        B.insert(num);
    }

    vector<int> v;
    for (const auto& ele : A) {
        if (B.find(ele) == B.end())
            v.push_back(ele);
    }

    if (v.size() != 0) {
        sort(v.begin(), v.end());

        cout << v.size() << '\n';
        for (const auto& ele : v) {
            cout << ele << " ";
        }
    } else
        cout << 0;

    return 0;
}