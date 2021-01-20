/*  13300 방 배정
    사이즈 주어지면 그냥 고정 배열로 푸는게 나은 듯..!
    벡터에 너무 의존하는 경우가 있는 거 같음.
*/
#include<iostream>

using namespace std;

int arr[2][6];

int solve(int k)
{
    int result = 0;

    for(int i=0;i<2;i++)
    {
        for(int j= 0; j<6;j++)
        {
           // 정원보다 작거나 같은 경우.
           result += arr[i][j] / k;

            // 정원보다 큰경우 방 하나 수 늘림.
            if(arr[i][j] % k !=0)
                result++; 
        }
    }
    
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 학생 수, 최대 인원 수
    int n, k;
    cin >> n >> k;

    while(n--)
    {
        // 성별, 학년
        int gender, grade;
        cin >> gender >> grade;
        arr[gender][--grade]++;
    }

    cout << solve(k) << '\n';

    return 0;
}