/* Structure of linked list Node
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
    Node* addOne(Node* head) {
        // code here
        int c = 0,a = 1;
        Node* node = head;
        Node* prev = NULL;
        while(node){
            Node* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        Node* nxtNode = NULL;
        while(prev){
            int add = prev->data+a+c;
            if(a) a = 0;
            Node* newNode;
            if(add==10){
                c = 1;
                newNode = new Node(0);
            }
            else{
                c = 0;
                newNode = new Node(add);
            }
            newNode->next = nxtNode;
            nxtNode = newNode;
            prev = prev->next;
        }
        if(c){
            Node* newNode = new Node(c);
            newNode->next = nxtNode;
            nxtNode = newNode;
        }
        return nxtNode;
    }
};