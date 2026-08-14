class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        int n = s.size();
        stack<char> st;
        int i = 0;
        while(i<n){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                i++;
            }
            else{
                if(st.empty()) return false;
                char ch = st.top();
                if((ch!='(' && s[i]==')') || 
                (ch!='[' && s[i]==']') || (ch!='{' && s[i]=='}')){
                    return false;
                }
                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};