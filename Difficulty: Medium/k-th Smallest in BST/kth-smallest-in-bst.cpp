/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int kthSmallest(Node *root, int k) {
        // code here
        // inorder is the sorted of bst
        Node* curr = root;
        while(curr){
            if(!curr->left){
                k--;
                if(k==0) return curr->data;
                curr = curr->right;
            }
            else{
                Node* node = curr->left;
                while(node->right && node->right!=curr){
                    node = node->right;
                }
                if(!node->right){
                    node->right = curr;
                    curr = curr->left;
                }
                else{
                    node->right = NULL;
                    k--;
                    if(k==0) return curr->data;
                    curr = curr->right;
                }
            }
        }
        return -1;
    }
};