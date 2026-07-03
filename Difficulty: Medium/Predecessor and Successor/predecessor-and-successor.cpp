/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* node = root;
        Node* ans1 = NULL;
        while(node){
            if(node->data<key){
                ans1 = node;
                node = node->right;
            }
            else{
                node = node->left;
            }
        }
        node = root;
        Node* ans2 = NULL;
        while(node){
            if(node->data<=key){
                node = node->right;
            }
            else{
                ans2 = node;
                node = node->left;
            }
        }
        return {ans1,ans2};
    }
};