#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int customer;
    cin >> customer;

    while (customer) {
        map<string, set<string>> m;
        for (int i = 0; i < customer; i++) {
            string name;
            cin >> name;

            // 공백 문자열 처리
            string foods;
            getline(cin, foods);
            stringstream ss(foods);

            string tmp;
            while (ss >> tmp) {
                m[tmp].insert(name);
            }
        }

        for (auto& ele : m) {
            cout << ele.first << " ";
            for (auto& name : ele.second) {
                cout << name << " ";
            }
            cout << '\n';
        }

        cin >> customer;
        if (customer) cout << '\n';
    }

    return 0;
}