// 트리 순회
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char left;
    char right;
};

vector<Node> Tree(26);
void PreOrder(char n) {
    if (n == '.') return;

    int node_num = int(n - 'A');

    cout << n;
    PreOrder(Tree[node_num].left);
    PreOrder(Tree[node_num].right);
}

void InOrder(char n) {
    if (n == '.') return;
    int node_num = int(n - 'A');

    InOrder(Tree[node_num].left);
    cout << n;
    InOrder(Tree[node_num].right);
}

void PostOrder(char n) {
    if (n == '.') return;

    int node_num = int(n - 'A');
    PostOrder(Tree[node_num].left);
    PostOrder(Tree[node_num].right);
    cout << n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;

        int node_num = int(root - 'A');

        Tree[node_num].left = left;
        Tree[node_num].right = right;
    }

    PreOrder('A');
    cout << '\n';
    InOrder('A');
    cout << '\n';
    PostOrder('A');
    cout << '\n';

    return 0;
}