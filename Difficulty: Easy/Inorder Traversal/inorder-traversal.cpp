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
    vector<int> inOrder(Node* root) {
        // code here
        Node* curr = root;
        vector<int> ans;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node* node = curr->left;
                while(node->right!=NULL && node->right!=curr) node = node->right;
                if(node->right==NULL){
                    node->right = curr;
                    curr = curr->left;
                }
                else{
                    node->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};