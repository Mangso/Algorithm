// 윷놀이
#include <iostream>

using namespace std;

int main()
{
    int t = 3;

    while(t--){
        int arr[2] = {0};

        for(int i=0; i<4; i++)
        {
            int num;
            cin >> num;

            arr[num]++;
        }
        if(arr[0] == 1){
            cout << 'A' << '\n';
        }
        else if(arr[0] == 2){
            cout << 'B' << '\n';
        }
        else if (arr[0] == 3){
            cout << 'C' << '\n';
        }
        else if (arr[0] == 4){
            cout << 'D' << '\n';
        }
        else
            cout << 'E' << '\n';
    }

    return 0;
}
