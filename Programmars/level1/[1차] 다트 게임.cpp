#include <bits/stdc++.h>

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> scores;
    vector<pair<char, int>> options;

    int c;
    for (int i = 0; i < int(dartResult.size()); i++) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            if (i > 0 && dartResult[i - 1] >= '0' && dartResult[i - 1] <= '9') {
                string s;
                s += dartResult[i - 1];
                s += dartResult[i];

                c = stoi(s);
            } else
                c = int(dartResult[i] - '0');
        } else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            if (dartResult[i] == 'S') {
                c = pow(c, 1);
            } else if (dartResult[i] == 'D') {
                c = pow(c, 2);
            } else if (dartResult[i] == 'T') {
                c = pow(c, 3);
            }

            scores.push_back(c);
        } else {
            options.push_back({dartResult[i], i / 3});
        }
    }

    for (auto ele : options) {
        if (ele.first == '*') {
            for (int i = ele.second - 1; i <= ele.second; i++) {
                scores[i] *= 2;
            }
        } else {
            scores[ele.second] = -scores[ele.second];
        }
    }

    answer = accumulate(scores.begin(), scores.end(), 0);
    return answer;
}