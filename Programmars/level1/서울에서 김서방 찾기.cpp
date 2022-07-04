#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";

    auto ret = find(seoul.begin(), seoul.end(), "Kim");
    string idx = to_string(ret - seoul.begin());

    answer += idx;
    answer += "에 있다";
    return answer;
}