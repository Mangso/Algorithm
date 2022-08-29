#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> MakeVector(string s, int size) {
    vector<string> v;
    for (int i = 0; i < int(s.size()); i += size) {
        v.push_back(s.substr(i, size));
    }

    return v;
}

int solution(string s) {
    int answer = 1001;
    int criteria = s.size() / 2;

    if (s.size() == 1) return 1;

    for (int i = 1; i <= criteria; i++) {
        vector<string> v = MakeVector(s, i);

        string compress = "";
        string base_word = v[0];
        int cnt = 1;
        for (int i = 1; i < int(v.size()); i++) {
            if (base_word == v[i]) {
                cnt++;
                continue;
            } else {
                if (cnt != 1)
                    compress += (to_string(cnt) + base_word);
                else
                    compress += base_word;

                base_word = v[i];
                cnt = 1;
            }
        }

        if (cnt != 1)
            compress += (to_string(cnt) + base_word);
        else
            compress += base_word;

        answer = min(answer, int(compress.size()));
    }

    return answer;
}