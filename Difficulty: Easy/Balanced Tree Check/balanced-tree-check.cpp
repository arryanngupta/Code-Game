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
  
    int recFind(Node* node){
        if(!node) return 0;
        int l = recFind(node->left);
        int r = recFind(node->right);
        if(l==-1 || r==-1) return -1;
        if(abs(l-r)>1) return -1;
        return max(l,r)+1;
    }
  
    bool isBalanced(Node* root) {
        // code here
        return recFind(root)!=-1;
    }
};