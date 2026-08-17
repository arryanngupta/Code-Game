/* Definition for Node
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
  
    vector<vector<int>> ans;
    
    bool isLeaf(Node* node){
        return (node && !node->left && !node->right);
    }
    
    void recFind(Node* node,vector<int> a){
        if(isLeaf(node)){
            a.push_back(node->data);
            ans.push_back(a);
            return ;
        }
        a.push_back(node->data);
        if(node->left) recFind(node->left,a);
        if(node->right) recFind(node->right,a);
        a.pop_back();
    }
    
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<int> a;
        recFind(root,a);
        return ans;
    }
};