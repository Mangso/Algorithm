// 알파벳 개수
#include<iostream>
#include <string>

using namespace std;

int main()
{
    int alphabet[26] ={0};
    
    string str;
    cin >> str;
    
    for(int i=0;i<int(str.length());i++){
        alphabet[str[i]-'a']++;
    }

    for (auto &element : alphabet)
        cout << element << " ";

    return 0;
}

/*
    for 문 안에서 str.length(), str.size()
    벡터 size() 이런거 쓸 때 
    warning 뜸 
    
    기본적으로 size() 이런 길이 자료형은 unsigned int 라 그런듯
    int(c.size()) 이렇게 변형시키면 warning 뜨진 않음
*/