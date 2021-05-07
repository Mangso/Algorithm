// Dictionaries and Maps

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;

    // 생성하는 법 앞이 key, 뒤가 value
    map<string, int> m1;
    
    for (int i = 0; i < t; i++)
    {
        string name;
        int phoneNumber;
        cin >> name >> phoneNumber;

        // 삽입
        m1.insert(pair<string, int>(name, phoneNumber));
    }

    // 이런식으로 입력이 끝날 때 까지 실행 하는 방법이 있네.
    string find_name;
    while (cin >> find_name)
    {
        auto iter = m1.find(find_name);

        if (iter == m1.end())
        {
            cout << "Not found" << endl;
        }
        else
        {
            cout << iter->first << "=" << iter->second << endl;
        }
    }
    return 0;
}
