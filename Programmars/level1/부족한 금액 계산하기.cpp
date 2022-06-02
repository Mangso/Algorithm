#include <iostream>

using namespace std;

// 그냥 long long 나올 것 같으면 다 long long 으로 하는게 맘 편하다.
long long solution(int price, int money, int count) {
    long long total = 0;
    long long answer = -1;
    for (int i = 0; i < count; i++) {
        total += price * (i + 1);
    }

    std::cout << total;

    if (total > money)
        answer = total - money;
    else
        answer = 0;

    return answer;
}