// BOJ11328.cpp
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

vector<char> v1,v2;

void str2vec(string str1, string str2)
{
    for(auto &element: str1)
        v1.push_back(element);

    for (auto &element : str2)
        v2.push_back(element);
    
}

void solve()
{

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int flag = 0;

    for(int i=0; i < int(v1.size());i++)
    {
        if(v1[i] == v2[i]) flag =1;
        else {
            cout << "Impossible" << '\n';
            return;
        }
    }

    if (flag == 1)
        cout << "Possible" << '\n';
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string str1, str2;
        cin >> str1 >> str2;

        str2vec(str1, str2);

        solve();

        v1.clear();
        v2.clear();

    } 

    return 0;
}

/* 다른 풀이

    이게 엄청 더 깔끔함
    string도 범위기반 for문 쓸 수 있군..

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;

    while (n--) {
        vector<int> count(26);
        string s1, s2;
        cin >> s1 >> s2;

        for (char ch : s1)
            ++count[ch - 'a'];
        
        for (char ch : s2)
            --count[ch - 'a'];
        
        bool is_possible = true;

        for (int i : count) {
            if (i != 0) {
                is_possible = false;
                break;
            }
        }

        if (is_possible)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}
*/