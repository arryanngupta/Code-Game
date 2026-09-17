/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* lastTail = NULL;
        Node* currHead = NULL;
        Node* currTail = 0;
        Node* node = head;
        Node* prev = NULL;
        Node* newHead = NULL;
        while(node){
            int cnt = 0;
            while(node && cnt<k){
                if(cnt==0) currHead = node;
                cnt++;
                Node* nxtNode = node->next;
                node->next = prev;
                prev = node;
                node = nxtNode;
            }
            currTail = prev;
            if(!newHead) newHead = prev;
            if(lastTail) lastTail->next = currTail;
            lastTail = currHead;
        }
        lastTail->next = NULL;
        return newHead;
    }
};