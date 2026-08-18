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
  
    Node* find(Node* node){
        if(node->left==NULL){
            Node* temp = node->right;
            // delete node;
            return temp;
        }
        Node* temp = node->left;
        while(temp->right) temp = temp->right;
        temp->right = node->right;
        // Node* ans = node->left;
        // delete node;
        return node->left;
    }
  
    Node* delNode(Node* root, int x) {
        // code here
        // left ka rightest node right se join krdo or 
        // prev ke right node ko left wle se join krdo!
        Node* prev = NULL;
        Node* node = root;
        while(node){
            if(node->data>x){
                prev = node;
                node = node->left;
            }
            else if(node->data<x){
                prev = node;
                node = node->right;
            }
            else{
                if(!prev) return find(node);
                if(prev->data>x){
                    prev->left = find(node);
                    break;
                }
                else{
                    prev->right = find(node);
                    break;
                }
            }
        }
        return root;
    }
};