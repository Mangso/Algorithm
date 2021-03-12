// 괄호 (스택)

#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool solve(string bracket)
{
    stack<char> s;
    for (char c : bracket)
    {
        if (c == '(')
        {
            s.push(c);
        }
        else
        {
            if (s.empty())
            {
                return 0;
            }
            if (!s.empty())
            {
                char tmp = s.top();

                if (tmp == '(')
                    s.pop();
            }
        }
    }

    if(s.empty()) return 1;
    else return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string bracket;

        cin >> bracket;

        if(solve(bracket))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}