class Solution {
  public:
  
    vector<string> ans;
  
    void recFind(string curr,int open,int n){
        if(curr.size()>=n){
            if(open==0) ans.push_back(curr);
            return ;
        }
        string str = curr;
        if(open){
            str.push_back(')');
            recFind(str,open-1,n);
            str.pop_back();
        }
        str.push_back('(');
        recFind(str,open+1,n);
        str.pop_back();
    }
  
    vector<string> generateParentheses(int n) {
        // code here
        recFind("",0,n);
        return ans;
    }
};