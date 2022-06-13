#include <string>
#include <vector>

using namespace std;

const int INF = 20000001;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // 모든 정점들 간의 최단 경로를 저장할 2차원 테이블
    vector<vector<int>> minCostTable(n + 1, vector<int>(n + 1, INF));

    // 자기 자신에서 자기 자신으로 가는 최단 경로는 0
    for (int i = 1; i <= n; i++) {
        minCostTable[i][i] = 0;
    }

    // 플로이드 와샬 알고리즘을 돌리기 전에 다이렉트로 i->j 로 가는 가중치 업데이트 해줘야 함.
    // 왜냐? dist의 (i,j) 값은 i-> 경유지 -> j 를 의미하니까
    for (auto &edge : fares) {
        minCostTable[edge[0]][edge[1]] = edge[2];
        minCostTable[edge[1]][edge[0]] = edge[2];
    }

    // 플로이드 와샬
    // k 거쳐 가는 노드
    for (int k = 1; k <= n; ++k) {
        // i = 출발 노드
        for (int i = 1; i <= n; i++) {
            // j = 도착 노드
            for (int j = 1; j <= n; j++) {
                if (minCostTable[i][k] + minCostTable[k][j] < minCostTable[i][j]) {
                    minCostTable[i][j] = minCostTable[i][k] + minCostTable[k][j];
                }
            }
        }
    }

    int answer = INF;
    for (int i = 1; i <= n; i++) {
        answer = min(answer, minCostTable[s][i] + minCostTable[i][a] + minCostTable[i][b]);
    }
    return answer;
}