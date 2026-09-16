/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    unordered_map<int,int> mpp;
    
    Node* recFind(int i1,int j1,int i2,int j2,int n,int m,
    vector<int> &inorder, vector<int> &postorder){
        if(i1>j1) return NULL;
        Node* newNode = new Node(postorder[j2]);
        int idx = mpp[postorder[j2]];
        newNode->left = recFind(i1,idx-1,i2,j2-(j1-idx)-1,n,m,inorder,postorder);
        newNode->right = recFind(idx+1,j1,j2-(j1-idx),j2-1,n,m,inorder,postorder);
        return newNode;
    }
  
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int n = inorder.size(),m = postorder.size();
        for(int i = 0; i<n; i++) mpp[inorder[i]]=i;
        return recFind(0,n-1,0,m-1,n,m,inorder,postorder);
    }
};