// 이진 검색 트리
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class BST {
   private:
    node* root = nullptr;

    void insert_impl(node* current, int value) {
        if (value < current->data) {
            if (!current->left)
                current->left = new node{value, NULL, NULL};
            else
                insert_impl(current->left, value);
        } else {
            if (!current->right)
                current->right = new node{value, NULL, NULL};
            else
                insert_impl(current->right, value);
        }
    }

    // 후위 순회
    void postorder_impl(node* start) {
        if (!start) return;

        postorder_impl(start->left);
        postorder_impl(start->right);
        std::cout << start->data << '\n';
    }

   public:
    BST(){};
    ~BST(){};
    void insert(int value) {
        // 루트 노드 없을 때
        if (!root)
            root = new node{value, NULL, NULL};
        else
            insert_impl(root, value);
    }
    void postorder() { postorder_impl(root); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BST bst;

    int num;
    while (cin >> num) {
        bst.insert(num);
    }

    bst.postorder();

    return 0;
}