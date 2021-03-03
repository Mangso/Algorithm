// 회전하는 큐

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    deque<int> d;

    for (int i = 1; i <= n; i++)
        d.push_back(i);

    int count = 0;
    while (m--)
    {
        int num;
        cin >> num;

        int index;

        // index 찾고.
        for (int i = 0; i < d.size(); i++)
        {
            if (d[i] == num)
            {
                index = i;
                break;
            }
        }

        // 왼쪽으로 가는게 더 가까운 경우.
        if (index < d.size() - index)
        {
            while (1)
            {
                if (d.front() == num)
                {
                    d.pop_front();
                    break;
                }

                ++count;
                d.push_back(d.front());
                d.pop_front();
            }
        }
        // 오른쪽으로 가는게 더 가까운 경우
        else
        {
            while (1)
            {
                if (d.front() == num)
                {
                    d.pop_front();
                    break;
                }
                ++count;
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }

    cout << count;

    return 0;
}