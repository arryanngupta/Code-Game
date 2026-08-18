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
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        Node* curr = root;
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
                    ans.push_back(curr->data);
                    curr = curr->left;
                }
                else{
                    node->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};