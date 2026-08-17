/* Structure of binary tree node
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
    vector<int> serialize(Node *root) {
        //  code here
        if(!root) return {};
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size(),cnt = 0;
            while(cnt<len){
                cnt++;
                Node* node = q.front();
                q.pop();
                if(node) ans.push_back(node->data);
                else ans.push_back(-1);
                if(node){
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return ans;
    }

    Node *deSerialize(vector<int> &arr) {
        
        //  code here
        int n = arr.size();
        if(n==0) return NULL;
        queue<Node*> q;
        Node* root = new Node(arr[0]);
        q.push(root);
        int i = 1;
        while(!q.empty() && i<n){
            Node* node = q.front();
            q.pop();
            
            if(arr[i]!=-1){
                Node* l = new Node(arr[i]);
                node->left = l;
                q.push(l);
            }
            i++;
            if(i>=n) break;
            if(arr[i]!=-1){
                Node* r = new Node(arr[i]);
                node->right = r;
                q.push(r);
            }
            i++;
        }
        return root;
    }
};