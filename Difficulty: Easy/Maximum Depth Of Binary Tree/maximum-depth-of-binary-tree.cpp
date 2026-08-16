/* The Node structure is
class Node {
public:
    int data;
    Node* left;
    Node* right;

};
}; */

class Solution {
  public:
  
    int recFind(Node* root){
        if(!root) return 0;
        int l = recFind(root->left);
        int r = recFind(root->right);
        return max(l,r)+1;
    }  
  
    int maxDepth(Node *root) {
        // code here
        return recFind(root);
    }
};
