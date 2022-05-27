#include <iostream>
#include <string>
#include <vector>

std::string solution(std::string phone_number) {
    std::string answer = phone_number;
    std::string star;
    int number_size = phone_number.size();

    for (int i = 0; i < number_size - 4; i++) {
        star += "*";
    }

    answer.replace(0, number_size - 4, star);
    return answer;
}

// string 의 replace
// str.replace(문자열 시작 위치, 길이, 치환할 문자열)

/* Ideal Solution

#include <iostream>
#include <string>
#include <vector>

std::string solution(std::string phone_number) {
    std::string answer = phone_number;

    for (int i = 0; i < answer.size() - 4; i++) {
        answer.replace(i, 1, "*");
        // answer[i] = '*'; 이렇게도 가능.
    }

    return answer;
}
*/