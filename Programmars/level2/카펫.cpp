// 카펫
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int B, Y;

vector<pair<int, int>> makePair(int total) {
    unordered_set<int> us;
    vector<int> v;
    for (int i = 1; i <= total; i++) {
        if (total % i == 0) {
            v.push_back(i);
            us.insert(i);
        }
    }

    vector<pair<int, int>> tmp;

    for (int i = 1; i < v.size() - 1; i++) {
        int target = total / v[i];

        if (v[i] <= target && us.find(target) != us.end()) {
            tmp.push_back({target, v[i]});
        }
    }

    return tmp;
}

bool Check(const pair<int, int> p) {
    int row = p.first;
    int col = p.second;
    vector<vector<int>> board(row, vector<int>(col));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                board[i][j] = 1;
            }
        }
    }
    int b, y;
    b = y = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 1)
                b++;
            else
                y++;
        }
    }

    if (B == b && Y == y) return true;

    return false;
}

vector<int> solution(int brown, int yellow) {
    /*
        Return : 카펫의 가로, 세로 크기.
    */
    B = brown;
    Y = yellow;

    int total = brown + yellow;
    vector<pair<int, int>> v;
    v = makePair(total);

    pair<int, int> p;
    for (auto ele : v) {
        if (Check(ele)) {
            p = ele;
            break;
        }
    }
    vector<int> answer;
    answer.push_back(p.first);
    answer.push_back(p.second);
    return answer;
}