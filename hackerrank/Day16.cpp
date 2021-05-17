// Day16: Exceptions
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    getline(cin, S);

    try
    {
        int _num;
        _num = stoi(S);
        cout << _num << endl;
    }
    catch (exception a)
    {
        cout << "Bad String";
    }
    return 0;
}
