/* 외계인의 기타연주
    vector.pop_back()
    vector.back() 도 있구나
    stl vector 좀 많이 알아두면 편할듯
    stack이나 2차원 배열 계속 써야하나 생각했는데 어렵군
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p;
    cin >> n >> p;

    int count = 0;
    vector<int> v[6];

    while (n--)
    {
        int guitar, pret;
        cin >> guitar >> pret;

        // 해당하는 줄 비어있지 않고 프렛 다른경우
        while (!v[guitar - 1].empty() && v[guitar - 1].back() > pret)
        {
            v[guitar - 1].pop_back();
            count++;
        }

        if (!v[guitar-1].empty() && v[guitar-1].back()== pret)
            continue;
        
        v[guitar-1].push_back(pret);
        count++;
    }

    cout << count;

    return 0;
}