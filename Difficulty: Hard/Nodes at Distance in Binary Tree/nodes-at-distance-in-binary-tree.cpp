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
};
*/
class Solution {
  public:
  
    vector<int> ans;
    
    unordered_map<int,Node*> mpp;
    
    Node* temp;
    
    void recFind(Node* node,int target,int k,unordered_map<Node*,int> &visited){
        if(!node) return ;
        if(k==0){
            ans.push_back(node->data);
            return ;
        }
        visited[node]=1;
        if(node->left && !visited.count(node->left)) recFind(node->left,target,k-1,visited);
        if(node->right && !visited.count(node->right)) recFind(node->right,target,k-1,visited);
        if(mpp[node->data] && !visited.count(mpp[node->data])) recFind(mpp[node->data],target,k-1,visited);
    }
    
    void preorder(Node* node,Node* par,int target){
        if(!node) return ;
        mpp[node->data] = par;
        if(node->data==target) temp = node;
        preorder(node->left,node,target);
        preorder(node->right,node,target);
    }
  
    vector<int> kDistanceNodes(Node* root, int target, int k) {
        // code here
        ans.clear();
        if(!root) return {};
        temp = NULL;
        preorder(root,NULL,target);
        unordered_map<Node*,int> visited;
        recFind(temp,target,k,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};