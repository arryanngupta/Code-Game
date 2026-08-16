/* Structure of Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    
    void recFind(Node* node,vector<int> &ans){
        if(!node) return ;
        ans.push_back(node->data);
        recFind(node->left,ans);
        recFind(node->right,ans);
    }
  
    vector<int> preOrder(Node* root) {
        // code here
        // root,left,right
        vector<int> ans;
        recFind(root,ans);
        return ans;
        
    }
};