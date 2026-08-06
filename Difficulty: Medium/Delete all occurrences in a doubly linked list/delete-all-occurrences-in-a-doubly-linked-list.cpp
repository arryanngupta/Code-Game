/* a Node of the doubly linked list
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
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {
        // code here
        Node* last = NULL;
        Node* newHead = NULL;
        Node* node = head;
        while(node){
            if(node->data==x){
                Node *nxtNode = node->next;
                Node* delNode = node;
                if(last) last->next = node->next;
                if(node->next) node->next->prev = last;
                delete delNode;
                node = nxtNode;
            }
            else{
                if(!newHead) newHead = node;
                last = node;
                node = node->next;
            }
        }
        return newHead;
    }
};