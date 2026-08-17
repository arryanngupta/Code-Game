/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  
    unordered_map<int,Node*> mpp;
    Node* temp;
    
    void preorder(Node* node,Node* par,int target){
        if(!node) return ;
        mpp[node->data] = par;
        if(node->data==target) temp = node;
        preorder(node->left,node,target);
        preorder(node->right,node,target);
    }
  
    int minTime(Node* root, int target) {
        // code here
        temp = NULL;
        preorder(root,NULL,target);
        queue<Node*> q;
        unordered_map<Node*,int> vis;
        q.push(temp);
        vis[temp] = 1;
        int lvl = 0;
        while(!q.empty()){
            int len = q.size(),cnt = 0;
            lvl++;
            while(cnt<len){
                cnt++;
                Node* node = q.front();
                q.pop();
                if(node->left && !vis.count(node->left)){
                    vis[node->left]= 1;
                    q.push(node->left);
                }
                if(node->right && !vis.count(node->right)){
                    q.push(node->right);
                    vis[node->right] = 1;
                }
                if(mpp[node->data] && !vis.count(mpp[node->data])){
                    q.push(mpp[node->data]);
                    vis[mpp[node->data]] = 1;
                }
            }
        }
        return lvl-1;
    }
};