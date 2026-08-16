/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            lvl++;
            int len = q.size(),cnt = 0;
            vector<int> a;
            while(cnt<len){
                cnt++;
                Node* node = q.front();
                q.pop();
                a.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(lvl%2==0) reverse(a.begin(),a.end());
            for(auto it: a){
                ans.push_back(it);
            }
        }
        return ans;
    }
};