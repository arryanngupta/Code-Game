/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        queue<Node*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int len = q.size();
            int cnt = 0;
            while(cnt<len){
                cnt++;
                Node* node = q.front();
                ans.push_back(node->data);
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};