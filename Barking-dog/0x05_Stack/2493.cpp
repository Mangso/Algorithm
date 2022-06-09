// 탑

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    stack<pair<int, int>> tower;
    cin >> n;
    tower.push({100000001, 0});
    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        while (tower.top().first < height) {
            tower.pop();
        }
        cout << tower.top().second << " ";
        tower.push({height, i});
    }

    return 0;
}