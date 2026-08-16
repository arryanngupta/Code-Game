/*Structure of binary tree Node 
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
  
    int maxi;
  
    int recFind(Node* root){
        if(!root) return 0;
        int lh = recFind(root->left);
        int rh = recFind(root->right);
        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
  
    int diameter(Node* root) {
        // code here
        maxi = 0;
        recFind(root);
        return maxi;
    }
};