// 쇠막대기

#include<iostream>
#include<stack>
#include<string>


using namespace std;

int main()
{
    
    string bar;
    cin >> bar;

    stack<int> s;
    int sum =0;

    for(int i=0; i< bar.size();i++)
    {
        if(bar[i] == '('){
            s.push(bar[i]);
        }
        else{
            s.pop();

            // 파이프가 끝난 경우.
            if(bar[i-1]==')')
                sum += 1;
            // 레이저인 경우.
            else sum += s.size();
        }
    }

    cout << sum << '\n';

    return 0;

}