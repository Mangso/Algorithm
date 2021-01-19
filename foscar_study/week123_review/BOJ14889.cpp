// 스타트와 링크

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int team[21][21];
bool check[21];
int n;
int result = INT_MAX;

void solve(int cnt, int next)
{
    if(cnt == n/2){
        
        int start =0, link =0;

        for(int i=0 ;i< n; i++)
        {
            for(int j=0; j < n; j++)
            {
                if (check[i] == true && check[j] ==  true) start += team[i][j];
                if (check[i] == false && check[j] == false) link += team[i][j];
            }

            
        }
        int tmp = abs(start-link);
        result = min(result,tmp);

        return;
    }

    for (int i = next ; i < n; i++)
    {
        check[i] = true;
        solve(cnt + 1, i + 1);
        check[i] = false;
    }
}
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> team[i][j];

    solve(0,1);

    cout << result;

    return 0;
}