/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int len = q.size(),cnt = 0;
            while(cnt<len){
                cnt++;
                Node* node = q.front().first;
                int idx = q.front().second;
                q.pop();
                mpp[idx] = (node->data);
                if(node->left){
                    q.push({node->left,idx-1});
                }
                if(node->right){
                    q.push({node->right,idx+1});
                }
            }
        }
        vector<int> ans;
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};