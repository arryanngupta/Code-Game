/* Structure of doubly linked list Node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/
class Solution {
  public:
    Node* deleteHead(Node* head) {
        // code here
        Node* delNode = head;
        head = head->next;
        delete delNode;
        head->prev = NULL;
        return head;
    }
};
