/* Structure of Binary Tree Node
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
  
    void recFind(Node* node,vector<int> &ans){
        if(!node) return ;
        recFind(node->left,ans);
        recFind(node->right,ans);
        ans.push_back(node->data);
    }
  
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> ans;
        recFind(root,ans);
        return ans;
    }
};