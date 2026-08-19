/* Binary Tree Node Structure
class Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class BSTIterator{
public:
    stack<Node*> st;
    int rev;
    BSTIterator(Node* root,int reverse){
        rev=reverse;
        push(root);
    }
    void push(Node* node){
        while(node){
            st.push(node);
            if(!rev) node = node->left;
            else node = node->right;
        }
    }
    
    int getElement(){
        Node* temp = st.top();
        st.pop();
        if(!rev){
            push(temp->right);
        }
        else{
            push(temp->left);
        }
        return temp->data;
    }
    
};

class Solution {
  public:
    bool findTarget(Node *root, int target) {
        // code here.
        BSTIterator b1(root,0);
        BSTIterator b2(root,1);
        int i = b1.getElement();
        int j = b2.getElement();
        while(i<j){
            if((i+j)>target){
                j = b2.getElement();
            }
            else if((i+j)<target){
                i = b1.getElement();
            }
            else return true;
        }
        return false;
    }
};