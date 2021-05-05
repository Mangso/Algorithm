// Let's Review

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        vector<char> v1, v2;

        for (size_t i = 0; i < s.length(); i++)
        {
            if (i % 2 == 0)
                v1.push_back(s[i]);
            else
                v2.push_back(s[i]);
        }

        for (auto ele : v1)
            cout << ele;

        cout << " ";
        for (auto ele : v2)
            cout << ele;

        cout << endl;
    }
    return 0;
}
