// 통나무 건너뛰기
// 그리디

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int solve(vector<int> &tree)
{

    sort(tree.begin(), tree.end(), comp);

    int max_height = 0;

    for (int i = 2; i < tree.size(); i++)
    {
        int tmp = abs(tree[i] - tree[i - 2]);
        max_height = max(max_height, tmp);
    }

    return max_height;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> tree;

        for (int i = 0; i < n; i++)
        {
            int h;
            cin >> h;

            tree.push_back(h);
        }

        cout << solve(tree) << '\n';
    }

    return 0;
}