/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zeroHead = NULL;
        Node* zeroTail = NULL;
        Node* oneHead = NULL;
        Node* oneTail = NULL;
        Node* twoHead = NULL;
        Node* twoTail = NULL;
        Node* node = head;
        while(node){
            Node* newNode = new Node(node->data);
            if(node->data==0){
                if(!zeroHead){
                    zeroHead = newNode;
                }
                else{
                    zeroTail->next = newNode;
                }
                zeroTail = newNode;
            }
            else if(node->data==1){
                if(!oneHead){
                    oneHead = newNode;
                }
                else{
                    oneTail->next = newNode;
                }
                oneTail = newNode;
            }
            else{
                if(!twoHead){
                    twoHead = newNode;
                }
                else{
                    twoTail->next = newNode;
                }
                twoTail = newNode;
            }
            node = node->next;
        }
        if(zeroHead){
            if(oneHead){
                zeroTail->next = oneHead;
                oneTail->next = twoHead;
            }
            else{
                zeroTail->next = twoHead;
            }
            return zeroHead;
        }
        else if(oneHead){
            oneTail->next = twoHead;
            return oneHead;
        }
        return twoHead;
    }
};