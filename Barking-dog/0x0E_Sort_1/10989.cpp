// 수 정렬하기 3
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
    vector<int> v(10001);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v[num]++;
    }

    for (int i = 1; i < 10001; i++) {
        if (v[i]) {
            for (int j = 0; j < v[i]; j++) {
                cout << i << '\n';
            }
        }
    }

    return 0;
}