/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    unordered_map<int,int> mpp;
    
    Node* recFind(int i1,int j1,int i2,int j2,
    vector<int> &inorder, vector<int> &preorder,int n,int m){
        if(i1>j1) return NULL;
        int idx = mpp[preorder[i2]];
        Node* newNode = new Node(preorder[i2]);
        newNode->left = recFind(i1,idx-1,i2+1,i2+(idx-i1),inorder,preorder,n,m);
        newNode->right = recFind(idx+1,j1,i2+(idx-i1)+1,i2+(idx-i1)+j1-idx,inorder,preorder,n,m);
        return newNode;
    }
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = inorder.size(),m = preorder.size();
        for(int i = 0; i<n; i++) mpp[inorder[i]]=i;
        return recFind(0,n-1,0,m-1,inorder,preorder,n,m);
    }
};