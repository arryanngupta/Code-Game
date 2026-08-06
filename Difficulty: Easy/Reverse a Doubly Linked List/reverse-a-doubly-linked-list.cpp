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
        Node* nxtNode = NULL;
        while(node){
            Node* temp = node->next;
            node->next = nxtNode;
            if(nxtNode) nxtNode->prev = node;
            nxtNode = node;
            node = temp;
        }
        head = nxtNode;
        head->prev = NULL;
        return head;
    }
};