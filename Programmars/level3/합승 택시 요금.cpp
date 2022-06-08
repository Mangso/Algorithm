// 플로이드 와샬
#include <string>
#include <vector>

using namespace std;
#define INF 40000000

int Dist[200][200];

void floyd(int n) {
    // k = 거쳐가는 노드
    for (int k = 0; k < n; ++k) {
        // i = 출발 노드
        for (int i = 0; i < n; i++) {
            // j = 도착 노드
            for (int j = 0; j < n; j++) {
                if (Dist[i][k] + Dist[k][j] < Dist[i][j]) {
                    Dist[i][j] = Dist[i][k] + Dist[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // n 지점의 개수
    // s 출발 지점

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 시작점과 도착점이 같은 경우.
            if (i == j)
                Dist[i][j] = 0;
            else
                Dist[i][j] = INF;
        }
    }

    // 플로이드 와샬
    for (auto edge : fares) {
        // 출발점, 도착점, 비용
        Dist[edge[0] - 1][edge[1] - 1] = edge[2];
        // 방향성이 없기 때문에 반대방향도 같은 비용
        Dist[edge[1] - 1][edge[0] - 1] = edge[2];
    }

    floyd(n);
    // idx를 0부터 시작하니까.
    --s;
    --a;
    --b;

    // 최소 비용
    int answer = INF;
    for (int k = 0; k < n; k++) {
        // 시작점에서 합승까지 비용 + k에서 a 가는 비용 + k에서 b 가는 비용
        answer = min(answer, Dist[s][k] + Dist[k][a] + Dist[k][b]);
    }
    return answer;
}