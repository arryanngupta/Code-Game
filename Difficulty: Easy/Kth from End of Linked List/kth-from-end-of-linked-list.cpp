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
        int cnt = 0;
        node = head;
        while(cnt<(n-k)){
            cnt++;
            node = node->next;
        }
        return node->data;
    }
};