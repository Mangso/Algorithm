#include <iostream>
#include <vector>

using namespace std;

void Solve(int num) {
    vector<int> fibo;

    fibo.push_back(1);
    fibo.push_back(2);

    int len = fibo.size();

    while (len < 45) {
        int sum = fibo[len - 2] + fibo[len - 1];

        fibo.push_back(sum);
        len++;
    }

    vector<int> v;
    int idx = len - 1;
    while (num >= 1) {
        if (num == 1) {
            v.push_back(1);
            break;
        }

        while (idx >= 0 && fibo[idx] > num) {
            idx--;
        }

        v.push_back(fibo[idx]);
        num -= fibo[idx];
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    int num;
    while (t--) {
        cin >> num;
        Solve(num);
    }

    return 0;
}
