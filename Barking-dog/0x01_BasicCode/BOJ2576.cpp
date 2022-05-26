// 홀수
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t = 7;
    vector<int> v;

    while(t--)
    {
        int num;
        cin >> num;

        if (num % 2 != 0) v.push_back(num);
    }

    // 벡터가 비어있지 않을 때
    if (!v.empty()){
        int sum = 0;
        int min_result = *min_element(v.begin(), v.end());

        for (auto element : v)
            sum += element;

        cout << sum << '\n'<< min_result;
    }
    else cout << -1;

    return 0;
}

