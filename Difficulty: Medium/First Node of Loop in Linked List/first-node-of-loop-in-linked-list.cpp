/*
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int cycleStart(Node* head) {
        // code here
        Node* fast = head;
        Node* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                Node* node = head;
                while(slow != node){
                    slow = slow->next;
                    node = node->next;
                }
                return node->data;
            }
        }
        return -1;
    }
};