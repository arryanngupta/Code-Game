/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(!root) return NULL;
        if(root->data==n1 || root->data == n2) return root;
        Node* l = lca(root->left,n1,n2);
        Node* r = lca(root->right,n1,n2);
        if(!l) return r;
        if(!r) return l;
        return root;
    }
};