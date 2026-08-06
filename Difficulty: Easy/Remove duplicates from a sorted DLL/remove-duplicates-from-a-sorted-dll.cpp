/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        // code here
        Node* node = headRef;
        Node* newHead = NULL;
        Node* last = NULL;
        while(node){
            if(!last){
                newHead = node;
                last = node;
                node = node->next;
            }
            else{
                if(node->data==last->data){
                    Node* delNode = node;
                    Node* nxtNode = node->next;
                    last->next = node->next;
                    if(node->next) node->next->prev = last;
                    delete delNode;
                    node = nxtNode;
                }
                else{
                    last = node;
                    node = node->next;
                }
            }
        }
        return newHead;
    }
};