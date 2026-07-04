/* Tree node structure 
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class NodeDetails{
public:
    int mini,maxi,len;
    NodeDetails(int mini,int maxi,int len){
        this->mini = mini;
        this->maxi = maxi;
        this->len = len;
    }
};

class Solution {
  public:
  
    
  
    NodeDetails recFind(Node* node){
        if(node==NULL) return NodeDetails(INT_MAX,INT_MIN,0);
        auto l = recFind(node->left);
        auto r = recFind(node->right);
        if(node->data>l.maxi && node->data<r.mini) 
            return NodeDetails(min(l.mini,node->data),max(node->data,r.maxi),l.len+r.len+1);
        else
            return NodeDetails(INT_MIN,INT_MAX,max(l.len,r.len));
    }
  
    int largestBst(Node *root) {
        // code here
        // leftLargest < node < rightSmallest
        return recFind(root).len;
    }
};