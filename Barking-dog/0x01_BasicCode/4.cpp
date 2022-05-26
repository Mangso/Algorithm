#include <iostream>

int func4(int n)
{
   int val = 1;
   while (2*val <= n) val *= 2;
   return val;
}

int main()
{
    std::cout << func4(9) << std::endl;
    std::cout << func4(793953651) << std::endl;
    std::cout << func4(756580036) << std::endl;

    return 0;
}

// 시간복잡도 O(sqrt(N))
// n이 2^k 이상 2^k+1 미만이라고 할 떄, while 문안에서 val은 최대 k번만
// 커짐 val은 2^k 형태가 되고, 시간복잡도 O(k)
// k는 log n 이니 시간복잡도는 O(lgn) 이다.

