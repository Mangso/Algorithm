// 알파벳 개수
#include<iostream>
#include <string>

using namespace std;

int main()
{
    int alphabet[26] ={0};
    
    string str;
    cin >> str;
    
    for(int i=0;i<str.size();i++){
        alphabet[str[i]-'a']++;
    }

    for (auto element : alphabet)
        cout << element << " ";

    return 0;
}