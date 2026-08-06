/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        Node* node = head;
        int cnt = 0;
        while(node){
            node = node->next;
            cnt++;
        }
        return cnt;
    }
};