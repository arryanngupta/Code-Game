/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    bool recFind(Node* node1,Node* node2){
        if(node1 && node2 && node1->data!=node2->data) return false;
        if((!node1 && node2) || (node1 && !node2)) return false;
        if(!node1 && !node2) return true;
        return recFind(node1->left,node2->right);
    }
  
    bool isSymmetric(Node* root) {
        // code here
        return recFind(root,root);
    }
};