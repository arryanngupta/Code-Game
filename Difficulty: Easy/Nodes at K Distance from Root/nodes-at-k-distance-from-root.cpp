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
  
    vector<int> ans;
    
    void recFind(Node* node,int k){
        if(!node) return;
        if(k==0){
            ans.push_back(node->data);
            return ;
        }
        recFind(node->left,k-1);
        recFind(node->right,k-1);
    }
  
    vector<int> kdistance(Node *root, int k) {
        // code here
        recFind(root,k);
        return ans;
    }
};