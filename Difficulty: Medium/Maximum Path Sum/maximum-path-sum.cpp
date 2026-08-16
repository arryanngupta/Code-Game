/* Structure of binary tree node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  
    int maxi;
  
    int recFind(Node* node){
        if(!node) return 0;
        int l = max(0,recFind(node->left));
        int r = max(0,recFind(node->right));
        maxi = max(maxi,l+r+node->data);
        return max(0,node->data+max(l,r));
    }
  
    int findMaxSum(Node *root) {
        // code here
        maxi = -1e9;
        recFind(root);
        return maxi;
    }
};