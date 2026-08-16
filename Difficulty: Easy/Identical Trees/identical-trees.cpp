/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
  
    bool recFind(Node* n1,Node* n2){
        if(!n1 && !n2) return true;
        if((n1 && !n2) || (!n1 && n2)) return false;
        if(n1 && n2 && n1->data!=n2->data) return false;
        bool l = recFind(n1->left,n2->left);
        bool r = recFind(n1->right,n2->right);
        if(!l || !r) return false;
        return true;
    }
  
    bool isIdentical(Node* r1, Node* r2) {
        // code here
        return recFind(r1,r2);
    }
};