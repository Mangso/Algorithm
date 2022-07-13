// 나무 자르기

#include <iostream>
#include <vector>

using namespace std;

long long N, M;
vector<long long> trees;

// Decision
bool Check(const int mid) {  // mid 높이에 절단기 를 위치했을 때 m 이상의 나무를 얻을 수 있겠는가?
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (trees[i] > mid) sum += trees[i] - mid;
    }
    return sum >= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int h;
        cin >> h;
        trees.push_back(h);
    }

    int lo = 0, hi = 1e9;
    // 가장 낮은 나무의 길이가 0 이고 가장 높은 나무의 길이가 1e9이니까
    // lower bound는 정답이 될 수 있는 모든 범위를 나타낼 수 있나? ( 정답은 0 ~ max(v) - 1라 가능...?)

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (Check(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << '\n';

    return 0;
}