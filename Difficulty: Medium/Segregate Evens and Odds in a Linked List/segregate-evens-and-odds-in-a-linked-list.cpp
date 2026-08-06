/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
}; */
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node* node = head;
        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;
        while(node){
            Node* newNode = new Node(node->data);
            if(node->data%2==0){
                if(!evenHead){
                    evenHead = newNode;
                }
                else{
                    evenTail->next = newNode;
                }
                evenTail = newNode;
            }
            else{
                if(!oddHead) oddHead = newNode;
                else oddTail->next = newNode;
                oddTail = newNode;
            }
            node = node->next;
        }
        if(evenTail){
            evenTail->next = oddHead;
            return evenHead;
        }
        return oddHead;
    }
};