// Day17 : More Exceptions

#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
class Calculator
{
    // 생성자에 뭐 인수 없으면 안써도 되는듯.
    public:

        int power(int n, int p)
        {
            // n,p 둘중에 하나라도 0이면 에러 던짐.
            if (n < 0 || p < 0)
            {
                throw runtime_error("n and p should be non-negative");
            }
            return pow(n, p);
        }
};
int main()
{
    Calculator myCalculator = Calculator();
    int T, n, p;
    cin >> T;
    while (T-- > 0)
    {
        if (scanf("%d %d", &n, &p) == 2)
        {
            try
            {
                int ans = myCalculator.power(n, p);
                cout << ans << endl;
            }// 에러 던지면 여기서 잡음 짜쓰!
            catch (exception &e)
            {
                // 에러메시지 여기서 딱 잡아가지고 what() 메소드로 출력.
                cout << e.what() << endl;
            }
        }
    }
}