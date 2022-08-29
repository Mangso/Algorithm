#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool IsPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n == 3) return true;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v(numbers.begin(), numbers.end());
    unordered_set<int> us;
    sort(v.begin(), v.end());

    do {
        string s = "";
        for (int i = 0; i < v.size(); i++) {
            s += v[i];
            us.insert(stoi(s));
        }
    } while (next_permutation(v.begin(), v.end()));

    for (auto ele : us) {
        if (IsPrime(ele))
            answer++;
    }

    return answer++;
}