#include <iostream>
#include <string>
#include <vector>

using namespace std;

string GetThree(int n) {
    string s;
    while (n) {
        int tmp = n % 3;
        n /= 3;
        s += to_string(tmp);
    }

    return s;
}

int GetDecimal(string s) {
    int decimal = 0;
    int i = 1;
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        int num = *it - '0';
        decimal += num * i;
        i *= 3;
    }
    return decimal;
}

int solution(int n) {
    string s = GetThree(n);
    int answer = GetDecimal(s);
    return answer;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string GetThree(int n) {
    string s;
    while (n) {
        int tmp = n % 3;
        n /= 3;
        s += to_string(tmp);
    }

    return s;
}

int GetDecimal(string s) {
    int decimal = 0;
    int i = 1;
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        int num = *it - '0';
        decimal += num * i;
        i *= 3;
    }
    return decimal;
}

int solution(int n) {
    string s = GetThree(n);
    int answer = GetDecimal(s);
    return answer;
}