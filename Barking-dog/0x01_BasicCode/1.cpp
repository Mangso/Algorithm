#include <iostream>

int func1(int n)
{
    int sum = 0;
    for (int i = 0 ; i <=n ; i++){
        if (i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    } 
    return sum;
}

int main()
{

    std::cout << func1(16) << std::endl;
    std::cout << func1(34567) << std::endl;
    std::cout << func1(27639) << std::endl;
    return 0;
}

// 시간복잡도 O(n)