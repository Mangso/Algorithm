#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int s_size = s.size();

    if (s_size % 2 != 0)
        answer += s[s_size / 2];
    else {
        answer += s[s_size / 2 - 1];
        answer += s[s_size / 2];
    }
    return answer;
}