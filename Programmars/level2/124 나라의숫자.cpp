#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<char> country = {1, 2, 4};

string solution(int n) {
    string answer = "";
    while (n > 0) {
        answer += country[n % 3];
        if (n % 3 == 0)
            n = (n / 3) - 1;
        else
            n = n / 3;
    }

    reverse(answer.begin(), answer.end());
    return answer;
}