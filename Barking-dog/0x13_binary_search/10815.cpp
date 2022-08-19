// 숫자 카드
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        cout << binary_search(v.begin(), v.end(), num) << ' ';
    }

    return 0;
}