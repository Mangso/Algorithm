#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> days{"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> month{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    string answer = "";
    int total = 0;
    for (int i = 0; i < a - 1; i++) {
        total += month[i];
    }
    total += b - 1;

    return days[total % 7];
}