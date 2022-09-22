#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), greater<char>());
    return s;
}