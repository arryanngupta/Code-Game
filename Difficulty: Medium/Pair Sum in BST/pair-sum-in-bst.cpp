/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class BSTIterator{
public:
    stack<Node*> st;
    BSTIterator(Node* root,int reverse){
        pushLeft(root,reverse);
    }
    
    void pushLeft(Node* node,int reverse){
        while(node){
            st.push(node);
            if(reverse){
                node = node->right;
            }
            else node = node->left;
        }
    }
    
    int next(){
        Node* node = st.top();
        st.pop();
        pushLeft(node->right,0);
        return node->data;
    }
    
    int before(){
        Node* node = st.top();
        st.pop();
        pushLeft(node->left,1);
        return node->data;
    }
    
    bool hasElements(){
        return !st.empty();
    }
    
};


class Solution {
  public:
    bool findTarget(Node *root, int target) {
        // your code here.
        BSTIterator l(root,0);
        BSTIterator r(root,1);
        int i = l.next();
        int j = r.before();
        while(i<j){
            if(i+j>target){
                j = r.before();
            }
            else if(i+j<target){
                i = l.next();
            }
            else{
                return true;
            }
        }
        return false;
    }
};