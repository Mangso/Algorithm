#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
bool comp(string a, string b) {
    if (a[N] == b[N]) return a < b;
    return a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {
    N = n;

    stable_sort(strings.begin(), strings.end(), comp);
    for (auto ele : strings) std::cout << ele << " ";

    return strings;
}