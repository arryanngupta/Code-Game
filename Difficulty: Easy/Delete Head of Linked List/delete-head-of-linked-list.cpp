/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node *deleteHead(Node *head) {
        // code here
        Node* delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }
};
