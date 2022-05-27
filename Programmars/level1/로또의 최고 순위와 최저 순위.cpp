#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Ranking(int count) {
    switch (count) {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int hit_cnt = 0;
    int zero_cnt = 0;

    for (auto &ele : lottos) {
        if (*find(win_nums.begin(), win_nums.end(), ele) == ele) hit_cnt++;
        if (ele == 0) zero_cnt++;
    }

    int max_rank = Ranking(hit_cnt + zero_cnt);
    int min_rank = Ranking(hit_cnt);

    vector<int> v;
    v.push_back(max_rank);
    v.push_back(min_rank);
    return v;
}

/*
    배열에서 특정 원소를 찾는 함수 std::find

    - 해당 원소를 찾으면 해당 원소의 반복자를 반환 해줌, 존재하지 않으면 범위의 마지막 end() 반복자 반환
      auto it = find(v.begin(), v.end(), num);
      if (it == v.end()) // 못 찾으면
*/

/*
    특정 조건으로 찾을 수도 있음 --> std::find_if

    홀수들
    bool isOdd(int n){
        return n % 2 == 1;
    }

    auto it2 = find_if(v.begin() , v.end(), isOdd);
    while (it2 != v.end()) {
        cout << *it2 << "\n";
        it2 = find_if(it2+1, v.end(), isOdd);
    }

*/