#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_set<string> pre;
    for (const auto& phone : phone_book) {
        pre.insert(phone);
    }

    for (const auto& p : pre) {
        string phone_number = "";
        for (int i = 0; i < int(p.size()); i++) {
            phone_number += p[i];
            if (pre.find(phone_number) != pre.end() && phone_number != p)
                return false;
        }
    }

    return true;

    return answer;
}