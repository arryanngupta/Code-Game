/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    bool recFind(Node* node,int mini,int maxi){
        if(node==NULL) return true;
        if(node->data<=mini || node->data>=maxi) return false;
        int l = recFind(node->left,mini,min(maxi,node->data));
        bool r = recFind(node->right,max(mini,node->data),maxi);
        if(!l || !r) return false;
        return true;
    }
  
    bool isBST(Node* root) {
        // code here
        int mini=0,maxi=INT_MAX;
        return recFind(root,mini,maxi);
    }
};