/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* recFind(Node* node,Node* n1,Node* n2){
        if(node==NULL || node==n1 || node==n2) return node;
        if((n1->data<node->data && n2->data>node->data)|| 
        (n1->data>node->data && n2->data<node->data)) return node;
        if(n1->data>node->data) return recFind(node->right,n1,n2);
        else return recFind(node->left,n1,n2);
    }
  
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        return recFind(root,n1,n2);
    }
};