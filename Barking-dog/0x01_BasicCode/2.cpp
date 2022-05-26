#include <iostream>
#include <array>
#include <algorithm>

int func2(int arr[], int n)
{

    for(int i = 0 ; i < n; i++){
        if(std::find(arr, arr+n, 100-arr[i]) != arr+n){
            return 1;
        }
    }
    return 0;
}

int main(){

    int arr1[3] = {1, 52, 48};
    int arr2[2] = {50,42};
    int arr3[5] = {4, 13, 63, 87};
    std::cout << func2(arr1, 3) << std::endl;
    std::cout << func2(arr2, 3) << std::endl;
    std::cout << func2(arr3, 3) << std::endl;

    return 0;

}

// Way1
// Brute force 2중 for 문
// Time complexity O(n^2)

// Way2
// 시간복잡도 O(n)