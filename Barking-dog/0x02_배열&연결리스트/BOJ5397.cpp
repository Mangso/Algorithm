// 키로거
// 반복자, stl에 차츰 익숙해지고있다.
// end() 는 마지막이 아니라 마지막 다음임. 참고
#include <iostream>
#include <string>
#include <list>

using namespace std;

void solve(string str)
{

    list<char> pwd;

    // 커서 위치
    auto it = pwd.begin();

    for(int i =0 ;i <str.size() ; i++)
    {
        // '<'
        if(str[i] == '<'){
            if(it != pwd.begin())
                it--;
        }
        // '>'
        else if(str[i] == '>'){
            if(it != pwd.end()){
                it++;
            }
        }
        // '-'
        else if (str[i] == '-'){
            // 커서 왼쪽으로 옮기고 지움.
            if(it != pwd.begin()){
                it--;
                it = pwd.erase(it);
            }
        }
        // 문자, 해당하는 커서에 인서트
        else{
            pwd.insert(it,str[i]);
        }
    }

    for(auto &e : pwd)
        cout << e;

    cout << '\n';

    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str;
        cin >> str;

        solve(str);
    }

    return 0;
}