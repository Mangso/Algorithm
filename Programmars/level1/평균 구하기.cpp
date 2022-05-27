#include <numeric>
#include <string>
#include <vector>

double solution(std::vector<int> arr) {
    double answer = double(std::accumulate(arr.begin(), arr.end(), 0)) / arr.size();
    return answer;
}

// 배열의 합을 구할 때 쓰는 std::accumulate
// numeric 헤더 파일에 존재
// std::accumulate(first iter, last iter, initial value of the sum)