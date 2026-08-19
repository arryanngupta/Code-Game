/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    bool recFind(Node* node,int mini,int maxi){
        if(!node) return true;
        if(node->data<=mini || node->data>=maxi) return false;
        return recFind(node->left,mini,node->data) && recFind(node->right,node->data,maxi);
    }
    
    bool isBST(Node* root) {
        // code here
        return recFind(root,-1e9,1e9);
    }
};