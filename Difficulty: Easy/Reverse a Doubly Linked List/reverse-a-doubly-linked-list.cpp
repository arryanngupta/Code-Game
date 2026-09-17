/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* node = head;
        Node* p = NULL;
        while(node){
            Node* nxtNode = node->next;
            node->next = p;
            node->prev = nxtNode;
            p = node;
            node = nxtNode;
        }
        return p;
    }
};