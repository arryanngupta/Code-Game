/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    void pushLeft(Node* root,stack<Node*> &s){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
  
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int> ans;
        stack<Node*> st1;
        stack<Node*> st2;
        pushLeft(root1,st1);
        pushLeft(root2,st2);
        while(!st1.empty() || !st2.empty()){
            if(st2.empty() || (!st1.empty() && st1.top()->data<=st2.top()->data)){
                Node* node = st1.top();
                st1.pop();
                ans.push_back(node->data);
                pushLeft(node->right,st1);
            }
            else{
                Node* node = st2.top();
                st2.pop();
                ans.push_back(node->data);
                pushLeft(node->right,st2);
            }
        }
        return ans;
    }
};