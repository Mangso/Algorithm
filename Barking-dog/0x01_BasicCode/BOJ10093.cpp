// 숫자

#include <iostream>
#include <algorithm>

using namespace std;

// swap 지금 까지 항상 만들면서 했는데
// algorithm 헤더에 swap 함수가 있구나.
// 정수형 뿐만 아니라 템플릿 사용해서 벡터 자료형도 가능함.

int main()
{
    long long a,b;
    cin >> a >> b;

    if (a==b) cout << 0;
    if (a > b) swap(a,b);
    
    if (a != b){
        int t = b-a -1;
        cout << t << '\n';
        for(long long i= a+ 1; i< b ; i++)
        {
            cout << i  << " ";
        }
    }

    return 0;
}