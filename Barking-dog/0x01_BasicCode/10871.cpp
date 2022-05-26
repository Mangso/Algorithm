#include <iostream>
#include <array>

int main(){
    
    int n, x;
    std::cin >> n >> x;
    std::array<int,10001> arr;

    for (int i = 0 ; i < n ; i++){
        std::cin >> arr[i];
        if (arr[i] < x) std::cout << arr[i] << ' ';
    }
    return 0;
}