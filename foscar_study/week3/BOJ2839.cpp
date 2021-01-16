// 설탕 배달
#include <iostream>

void solve(int n){

    int bag_cnt = 0;

    while(n)
    {
        
        if (n % 5 == 0){
            n = n-5;
            bag_cnt++;
        }
        else if (n% 3 == 0 ){
            n = n-3;
            bag_cnt++;
        }
        else if (n > 5){
            n = n - 5;
            bag_cnt++;
        }
        else {
            bag_cnt = -1;
            break;
        }
        
    }

    std::cout << bag_cnt;
}
int main()
{
    int n;
    std::cin >> n;

    solve(n);
}