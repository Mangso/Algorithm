// 잃어버린 괄호
// 그리디

#include <iostream>
#include <stack>
#include <string>
#include <stack>

using namespace std;

string str;

int solve()
{
    int result = 0;
    string str_num="";
    int flag = 0;

    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] == '-' || str[i] == '+' || str[i] == '\0')
        {
            //  숫자 뒤가 - 인지 + 인지.

            // - 20 - 오면 -20 더함.
            if (flag)
                result -= stoi(str_num);
            else
                result += stoi(str_num);

            // 초기화.
            str_num = "";

            // - 면 flag 세움.
            if (str[i] == '-')
                flag = 1;
        }
        else
        {
            str_num += str[i];
        }

    }

    return result;
}
int main()
{
    cin >> str;
    cout << solve() << '\n';

    return 0;
}