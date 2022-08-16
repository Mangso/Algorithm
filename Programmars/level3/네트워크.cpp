#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> check;
int N;

void dfs(vector<vector<int>>& computers, int idx) {
    check[idx] = true;

    for (int i = 0; i < N; i++) {
        if (check[i] == false && computers[idx][i] == 1) {
            dfs(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    N = n;
    int answer = 0;

    check.resize(n);

    for (int i = 0; i < n; i++) {
        if (check[i] == false) {
            dfs(computers, i);
            answer++;
        }
    }
    return answer;
}