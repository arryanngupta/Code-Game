/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // code here
        Node* node = head;
        int cnt = 0;
        while(node){
            cnt++;
            node = node->next;
        }
        k = k%cnt;
        if(k==0) return head;
        cnt = 0;
        Node* prev = NULL;
        node = head;
        while(cnt<k){
            cnt++;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
        Node* newHead = node;
        while(node->next){
            node = node->next;
        }
        node->next = head;
        return newHead;
    }
};