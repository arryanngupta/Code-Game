/* Structure of a Binary Search Tree node
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
}; */

class Solution {
  public:
  
    void pushLeft(Node* node,stack<Node*> &st){
        while(node){
            st.push(node);
            node = node->left;
        }
    }
    
    vector<int> merge(Node *r1, Node *r2) {
        // code here
        stack<Node*> st1;
        stack<Node*> st2;
        pushLeft(r1,st1);
        pushLeft(r2,st2);
        vector<int> ans;
        while(!st1.empty() || !st2.empty()){
            if(st2.empty() || (!st1.empty() && st1.top()->data<=st2.top()->data)){
                Node* node = st1.top();
                ans.push_back(node->data);
                st1.pop();
                pushLeft(node->right,st1);
            }
            else{
                Node* node = st2.top();
                ans.push_back(node->data);
                st2.pop();
                pushLeft(node->right,st2);
            }
        }
        return ans;
    }
};