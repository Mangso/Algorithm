// 핸드폰 요금
#include<iostream>

using namespace std;

int arr[21];

int yungsik(int arr[], int n){
    
    int result=0;

    for(int i = 0; i<n; i++){
        int cost = (arr[i] / 30) + 1;
        result += 10 * cost;
    }

    return result;
}

int minsik(int arr[], int n){
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        int cost = (arr[i] / 60) + 1;
        result += 15 * cost;
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    

    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }

    int y = yungsik(arr,n);
    int m = minsik(arr,n);

    if(y < m) 
        cout << 'Y' << " " <<y << '\n';
    else if (y == m) 
        cout << 'Y' << " " << 'M' << " " << m <<'\n';
    else
        cout << 'M' << " " << m << '\n';

    return 0;
}