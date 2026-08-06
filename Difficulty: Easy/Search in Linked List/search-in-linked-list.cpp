/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        Node* node = head;
        while(node){
            if(node->data==key) return true;
            node = node->next;
        }
        return false;
    }
};
