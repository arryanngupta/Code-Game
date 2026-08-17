/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        if(!root) return {};
        map<int,int> mpp;
        queue<Node*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            int len = q.size(),cnt = 0;
            lvl++;
            while(cnt<len){
                cnt++;
                Node* node = q.front();
                q.pop();
                if(!mpp.count(lvl)) mpp[lvl] = node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        vector<int> ans;
        for(auto it: mpp) ans.push_back(it.second);
        return ans;
    }
};