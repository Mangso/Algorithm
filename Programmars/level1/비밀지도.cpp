#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

const int BITSET_SIZE = 16;
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    int num;
    for (int i = 0; i < n; i++) {
        num = arr1[i] | arr2[i];
        bitset<BITSET_SIZE> bs(num);

        string str_bit = bs.to_string();
        string tmp = str_bit.substr(BITSET_SIZE - n, n);

        string password;
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] == '1')
                password += '#';
            else
                password += ' ';
        }

        answer.push_back(password);
    }

    return answer;
}