
class Node{
  public:
    Node* links[2];
    Node(){
        for(int i = 0; i<2; i++) links[i] = nullptr;
    }
};

class Trie{
  public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        int n = word.size();
        Node* node = root;
        for(int i = 0; i<n; i++){
            if(!node->links[word[i]-'0']){
                Node* newNode = new Node;
                node->links[word[i]-'0'] = newNode;
            }
            node = node->links[word[i]-'0'];
        }
    }
    
    int find(string &word){
        int n = word.size();
        Node* node = root;
        int cnt = 32,ans = 0;
        for(int i = 0; i<n; i++){
            cnt--;
            int bit = word[i]-'0';
            if(node->links[!bit]){
                ans += (1<<cnt);
                node = node->links[!bit];
            }
            else node = node->links[bit];
        }
        return ans;
    }
};

class Solution {
  public:
  
    string bin(int n){
        string ans = "";
        while(n){
            ans += n%2+'0';
            n = n/2;
        }
        reverse(ans.begin(),ans.end());
        string s(32-ans.size(),'0');
        s += ans;
        return s;
    }
  
    int maxXor(vector<int> &arr) {
        // code here
        Trie t;
        for(auto it: arr){
            string s = bin(it);
            t.insert(s);
        }
        int maxi = 0;
        for(auto it: arr){
            string s = bin(it);
            maxi = max(maxi,t.find(s));
        }
        return maxi;
    }
};
