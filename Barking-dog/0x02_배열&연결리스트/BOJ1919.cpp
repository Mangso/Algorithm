// 애너그램 만들기

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int alpha1[26]={0};
    int alpha2[26]={0};
    int cnt =0;

    // 각 단어의 알파벳 숫자 갱신.
    for(auto &element : str1)
        alpha1[element-'a']++;

    for (auto &element : str2)
        alpha2[element - 'a']++;
    

    // 알파벳 숫자가 같지 않을 때 빼서 카운트
    // abs()
    for(int i=0;i<26;i++)
    {
        if (alpha1[i] != alpha2[i])
            cnt += abs(alpha1[i] - alpha2[i]);
    }

    cout << cnt;

    return 0;
}