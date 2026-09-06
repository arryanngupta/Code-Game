
struct Node{
public:
    Node* links[26];
    int flag;
    Node(){
        flag = false;
        for(int i = 0; i<26; i++){
            links[i] = NULL;
        }
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
            if(!node->links[word[i]-'a']){
                Node* newNode = new Node();
                node->links[word[i]-'a']=newNode;
            }
            node = node->links[word[i]-'a'];
        }
        node->flag = true;
    }
    
    bool prefix(string &word){
        int n = word.size();
        Node* node = root;
        for(int i = 0; i<n; i++){
            node = node->links[word[i]-'a'];
            if(!node->flag) return false;
        }
        return true;
    }
    
};

class Solution {
  public:    
    string longestValidWord(vector<string>& words) {
        // code here
        Trie t;
        for(auto it: words){
            t.insert(it);
        }
        string ans = "";
        for(auto it: words){
            if(t.prefix(it)){
                if(ans.empty()) ans = it;
                else if(ans.size()<it.size()) ans = it;
                else if(ans.size()==it.size() && it<ans) ans = it;
            }
        }
        return ans;
    }
};
