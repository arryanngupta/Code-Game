/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        Node* fast = head;
        Node* slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        Node* right = slow->next;
        Node* prev = NULL;
        while(right){
            Node* node = right->next;
            right->next = prev;
            prev = right;
            right = node;
        }
        Node* temp = head;
        while(prev && temp){
            if(prev->data!=temp->data) return false;
            prev = prev->next;
            temp = temp->next;
        }
        return true;
    }
};