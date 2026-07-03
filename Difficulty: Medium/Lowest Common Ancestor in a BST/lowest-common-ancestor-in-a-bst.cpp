/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* recFind(Node* node,Node* n1, Node* n2){
        if(!node || node==n1 || node==n2) return node;
        Node* l = recFind(node->left,n1,n2);
        Node* r = recFind(node->right,n1,n2);
        if(!l) return r;
        else if(!r) return l;
        else return node;
    }
  
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        return recFind(root,n1,n2);
    }
};