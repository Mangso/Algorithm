#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long tmp = num;
    int cnt = 0;

    while (1) {
        if (tmp == 1) break;
        if (tmp % 2 == 0)
            tmp /= 2;
        else
            tmp = (3 * tmp) + 1;

        cnt++;
        if (cnt == 500) return -1;
    }

    return cnt;
}