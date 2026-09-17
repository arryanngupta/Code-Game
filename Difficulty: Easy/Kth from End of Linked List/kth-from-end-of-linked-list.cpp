/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        int n = 0;
        Node* node = head;
        while(node){
            n++;
            node = node->next;
        }
        if(n-k+1<=0) return -1;
        // Node* fast = head;
        // Node* slow = head;
        // int cnt = 0;
        // while(cnt<k-1){
        //     fast = fast->next;
        //     cnt++;
        // }
        // while(fast->next){
        //     fast = fast->next;
        //     slow = slow->next;
        // }
        node = head;
        int cnt = 1;
        while(cnt<(n-k+1)){
            cnt++;
            node = node->next;
        }
        // return slow->data;
        return node->data;
    }
};