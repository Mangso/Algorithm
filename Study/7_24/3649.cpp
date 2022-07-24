#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;

    while (cin >> x >> n) {
        vector<int> legos;
        int hole_length = x * 10000000;

        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            legos.push_back(tmp);
        }

        sort(legos.begin(), legos.end());

        int l = 0;
        int r = legos.size() - 1;

        bool find = false;
        while (l < r) {
            int sum = legos[l] + legos[r];

            if (sum == hole_length) {
                find = true;
                break;
            }

            if (sum > hole_length)
                r--;
            else
                l++;
        }

        if (find)
            cout << "yes " << legos[l] << " " << legos[r] << '\n';
        else
            cout << "danger" << '\n';
    }

    return 0;
}