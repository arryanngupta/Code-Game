
class Node{
  public:
    Node* links[26];
    int cnt;
    Node(){
        for(int i = 0; i<26; i++) links[i] = NULL;
        cnt = 0;
    }
};

class Trie{
  public:
    Node* root;
    Trie(){
        root = new Node();
    }
    int insert(string &word){
        int n = word.size(),ans = 0;
        Node* node = root;
        for(int i = 0; i<n; i++){
            if(!node->links[word[i]-'a']){
                Node* newNode = new Node();
                node->links[word[i]-'a']=newNode;
                ans++;
            }
            node = node->links[word[i]-'a'];
            node->cnt++;
        }
        return ans;
    }
};

class Solution {
  public:
    int countSubs(string& s) {
        // code here
        Trie t;
        int ans = 0;
        int n = s.size();
        for(int i = 0; i<n; i++){
            string str = s.substr(i);
            ans += t.insert(str);
        }
        return ans;
    }
};