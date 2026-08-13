class Solution {
  public:
  
    vector<string> ans;
  
    vector<string> powerSet(string s) {
        // code here
        int n = s.size();
        ans.clear();
        for(int i = 0; i<pow(2,n); i++){
            string a = "";
            for(int bit = 0; bit<n; bit++){
                if((1<<bit)&i) a += s[bit];
            }
            ans.push_back(a);
        }
        return ans;
    }
};
