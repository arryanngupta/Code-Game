/* class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
  
    Node* recFind(int &idx,int ub,vector<int>& pre,int n){
        if(idx>=n || pre[idx]>=ub) return NULL;
        Node* root = new Node(pre[idx++]);
        root->left = recFind(idx,root->data,pre,n);
        root->right = recFind(idx,ub,pre,n);
        return root;
    }

    Node* preToBST(vector<int>& pre) {
        // code here
        int n = pre.size();
        int idx = 0;
        return recFind(idx,1e9,pre,n);
    }
};