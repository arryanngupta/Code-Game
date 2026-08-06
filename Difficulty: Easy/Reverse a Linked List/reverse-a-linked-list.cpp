/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        Node* node = head;
        Node* nxtNode = NULL;
        while(node){
            Node* temp = node->next;
            node->next = nxtNode;
            nxtNode = node;
            node = temp;
        }
        head = nxtNode;
        return head;
    }
};