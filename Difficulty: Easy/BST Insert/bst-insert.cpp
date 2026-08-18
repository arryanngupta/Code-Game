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
    Node* insert(Node* root, int key) {
        // code  here
        Node* prev = NULL;
        Node* node = root;
        while(node){
            if(node->data>key){
                prev = node;
                node = node->left;
            }
            else{
                prev = node;
                node = node->right;
            }
        }
        if(prev->data>key){
            prev->left = new Node(key);
        }
        else{
            prev->right = new Node(key);
        }
        return root;
    }
};