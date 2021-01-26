// 큐
// pop 에서 가장 앞에 빼라했는데
// 아무생각없이 back 함 (문제잘보자)

#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<int> q;
int num;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        string str;
        cin >> str;

        if (str == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (str == "pop")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (str == "size")
        {
            cout << q.size() << '\n';
        }
        else if (str == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if (str == "front")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
            }
        }
        else if (str == "back")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
            {
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}