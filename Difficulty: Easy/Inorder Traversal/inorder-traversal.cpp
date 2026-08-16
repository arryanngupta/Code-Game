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
        if(!node) return;
        recFind(node->left,ans);
        ans.push_back(node->data);
        recFind(node->right,ans);
    }
  
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        recFind(root,ans);
        return ans;
    }
};