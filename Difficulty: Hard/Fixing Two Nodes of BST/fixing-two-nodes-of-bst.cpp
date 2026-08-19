/* Structure of a Binary Search Tree node
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
    Node* correctBST(Node* root) {
        // code here
        Node* curr = root;
        Node* prev = NULL;
        Node* first = NULL;
        Node* middle = NULL;
        Node* last = NULL;
        while(curr){
            if(!curr->left){
                if(prev && curr->data<prev->data){
                    if(!first){
                        first = prev;
                        middle = curr;
                    }
                    else{
                        last = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            }
            else{
                Node* node = curr->left;
                while(node->right && node->right!=curr) node = node->right;
                if(!node->right){
                    node->right = curr;
                    curr = curr->left;
                }
                else{
                    node->right = NULL;
                    if(prev && curr->data<prev->data){
                        if(!first){
                            first = prev;
                            middle = curr;
                        }
                        else{
                            last = curr;
                        }
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        if(!last){
            swap(first->data,middle->data);
        }
        else{
            swap(first->data,last->data);
        }
        return root;
    }
};