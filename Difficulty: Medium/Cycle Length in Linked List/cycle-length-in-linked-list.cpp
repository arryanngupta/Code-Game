/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* fast = head;
        Node* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                Node* node = head;
                while(node!=slow){
                    node = node->next;
                    slow = slow->next;
                }
                slow = slow->next;
                int cnt = 1;
                while(slow!=node){
                    slow = slow->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
};