// Day15: Linked List
#include <iostream>
#include <cstddef>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class Solution
{
public:
    
    Node *insert(Node *head, int data)
    {
        // 처음 head 없으면 head 설정
        if (head == NULL)
        {
            return new Node(data);
        }
        // next 가리키는게 없으면 이어줌.
        else if (head->next == NULL)
        {
            head->next = new Node(data);
        }
        else // 가리키는게 있으면 
        {
            insert(head->next, data);
        }

        return head;
    }

    void display(Node *head)
    {
        Node *start = head;
        while (start)
        {
            cout << start->data << " ";
            start = start->next;
        }
    }
};
int main()
{
    Node *head = NULL;
    Solution mylist;
    int T, data;
    cin >> T;
    while (T-- > 0)
    {
        cin >> data;
        head = mylist.insert(head, data);
    }
    mylist.display(head);
}