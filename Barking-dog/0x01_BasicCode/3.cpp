#include <iostream>


int func3(int n){
    for(int i = 1; i * i <= n ;i ++){
        if(i*i == n) return 1;
    }
    return 0;
}

int main()
{
    std::cout << func3(9) << std::endl;
    std::cout << func3(793953651) << std::endl;
    std::cout << func3(756580036) << std::endl;

    return 0;
}

// 시간복잡도 O(sqrt(N))