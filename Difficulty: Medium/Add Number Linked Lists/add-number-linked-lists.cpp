/*
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
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        Node* node = head1;
        Node* prev1 = NULL;
        while(node){
            Node* temp = node->next;
            node->next = prev1;
            prev1 = node;
            node = temp;
        }
        Node* prev2 = NULL;
        node = head2;
        while(node){
            Node* temp = node->next;
            node->next = prev2;
            prev2 = node;
            node = temp;
        }
        int c = 0;
        Node* nxtNode = NULL;
        while(prev1 || prev2){
            int add = c;
            if(prev1) add += prev1->data;
            if(prev2) add += prev2->data;
            c = add/10;
            Node* newNode = new Node(add%10);
            newNode->next = nxtNode;
            nxtNode = newNode;
            if(prev1) prev1 = prev1->next;
            if(prev2) prev2 = prev2->next;
        }
        if(c){
            Node* newNode = new Node(c);
            newNode->next = nxtNode;
            nxtNode = newNode;
        }
        while(nxtNode && nxtNode->next && nxtNode->data==0) nxtNode = nxtNode->next;
        return nxtNode;
    }
};