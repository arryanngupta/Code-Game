/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void correctBST(Node* root) {
        // add code here.
        Node* curr = root;
        Node* first = NULL;
        Node* middle = NULL;
        Node* last = NULL;
        Node* prev = NULL;
        while(curr){
            if(curr->left==NULL){
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
                while(node->right && node->right!=curr){
                    node = node->right;
                }
                if(!node->right){
                    node->right = curr;
                    curr = curr->left;
                }
                else{
                    node->right = NULL;
                    // push;
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
        if(last){
            swap(first->data,last->data);
        }
        else swap(first->data,middle->data);
    }
};