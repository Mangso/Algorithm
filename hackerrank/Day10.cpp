// Binary numbers
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int getMaximum(int n)
{
    int nMax = 0;
    int cnt = 0;

    while (n > 0)
    {
        // 뒷자리부터 1이면 카운트
        if (n % 2 == 1)
        {
            cnt++;

            // cnt 계속 갱신.
            // 만약에 비트가 0이면 밑에서 cnt 를 초기화 하기에 
            // nMax가 갱신이 전에 최고값으로 갱신됨.
            if (nMax < cnt)
                nMax = cnt;
        }
        else
            cnt = 0;

        n = n / 2;
    }

    return nMax;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int result = getMaximum(n);

    cout << result;

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
