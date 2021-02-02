// 스택 수열
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

stack<int> s;
vector<int> v;
vector<char> c_vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int num;
    for (int i=0; i< n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    int idx = 0;
    for(int i = 1; i<=n;i++)
    {
        s.push(i);
        c_vec.push_back('+');

        while(!s.empty())
        {
            if(v[idx] == s.top())
            {
                s.pop();
                c_vec.push_back('-');
                idx++;
            }
            else break;
        }
    }

    if (s.empty()){
        for (auto e : c_vec)
            cout << e << '\n';
    }
    else{
        cout << "NO"<< '\n';
    } 

    return 0;
}