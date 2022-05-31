#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetDistance(std::pair<int, int> target_num, std::pair<int, int> pose) {
    int distance = abs(target_num.first - pose.first) + abs(target_num.second - pose.second);
    return distance;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";

    std::pair<int, int> l_pose, r_pose;

    l_pose = {3, 0};
    r_pose = {3, 2};

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            l_pose = {numbers[i] / 3, 0};
        } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            r_pose = {(numbers[i] / 3) - 1, 2};
        } else {
            std::pair<int, int> target_num;
            if (numbers[i] == 0)
                target_num = {3, 1};
            else
                target_num = {(numbers[i] / 3), 1};

            if (GetDistance(target_num, l_pose) > GetDistance(target_num, r_pose)) {
                answer += 'R';
                r_pose = target_num;
            } else if (GetDistance(target_num, l_pose) < GetDistance(target_num, r_pose)) {
                answer += 'L';
                l_pose = target_num;
            } else {
                if (hand == "right") {
                    answer += 'R';
                    r_pose = target_num;
                } else {
                    answer += 'L';
                    l_pose = target_num;
                }
            }
        }
    }
    return answer;
}