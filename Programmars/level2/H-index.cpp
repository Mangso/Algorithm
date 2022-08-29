#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    int max_ = *max_element(citations.begin(), citations.end());

    int h_index = 0;
    for (int i = 0; i < max_; i++) {
        int h = 0;
        int l = 0;
        for (int j = 0; j < citations.size(); j++) {
            if (citations[j] >= i) h++;
            if (citations[j] <= i) l++;
        }

        if (i >= h && l <= h) h_index = max(h_index, h);
    }
    return h_index;
}
/*

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] < i + 1) {
            return i;
        }
    }

    return citations.size();
}
*/