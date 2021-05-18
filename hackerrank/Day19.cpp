// Day19. INterfaces
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic
{
public:
    virtual int divisorSum(int n) = 0;
};
class Calculator : public AdvancedArithmetic
{
public:
    int s = 0;
    
    int divisorSum(int n)
    {
        int i = 0;
        
        for (i = 1; i * i < n; i++)
        {
            if (n % i == 0)
            {
                s += i;
                s += n / i;
            }
        }

        if (i * i == n)
            s += i;
        return s;
    }
    /*
    일반 버전
    int sum =0;
    for (int i=1; i<=n ;i++)
    {
        if (n % i == 0 ) sum +=i;
    }
    return sum;

    */
};

int main()
{
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator();
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n"
         << sum;
    return 0;
}