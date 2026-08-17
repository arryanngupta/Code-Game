class Solution {
  public:
  
    int find(Node* node,int flag){
        if(!node) return 0;
        int ans = 0;
        if(!flag) ans = 1+find(node->left,flag);
        else ans = 1+find(node->right,flag);
        return ans;
    }
  
    int recFind(Node* root){
        if(!root) return 0;
        int lh = find(root,0);
        int rh = find(root,1);
        if(lh==rh) return (1<<lh)-1;
        return recFind(root->left)+recFind(root->right)+1;
    }
    
    int countNodes(Node* root) {
        // code here
        return recFind(root);
    }
};