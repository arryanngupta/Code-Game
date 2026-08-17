/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    int recFind(Node* node){
        if(!node) return 0;
        if(!node->left && !node->right) return node->data;
        int l = recFind(node->left);
        int r = recFind(node->right);
        if(l==-1 || r==-1) return -1;
        if(l+r!=node->data) return -1;
        return l+r;
    }
  
    bool isSumProperty(Node *root) {
        // code here
        return recFind(root)!=-1;
    }
};