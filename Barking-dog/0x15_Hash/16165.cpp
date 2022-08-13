// 걸그룹 마스터 준석이
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_multimap<string, string> um;
    for (int i = 0; i < N; i++) {
        string group_name;
        int group_num;

        cin >> group_name >> group_num;

        for (int j = 0; j < group_num; j++) {
            string name;
            cin >> name;
            um.insert({group_name, name});
        }
    }

    for (int i = 0; i < M; i++) {
        string name;
        int quiz;
        cin >> name >> quiz;

        if (quiz == 0) {
            vector<string> group;
            auto range = um.equal_range(name);

            for (auto it = range.first; it != range.second; ++it) {
                group.push_back(it->second);
            }

            sort(group.begin(), group.end());

            for (const auto& ele : group) {
                cout << ele << '\n';
            }

        } else {
            for (const auto& ele : um) {
                if (ele.second.compare(name) == 0) {
                    cout << ele.first << '\n';
                }
            }
        }
    }

    return 0;
}