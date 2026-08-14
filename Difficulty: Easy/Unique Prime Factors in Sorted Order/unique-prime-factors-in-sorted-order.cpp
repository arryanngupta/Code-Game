class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<int> ans;
        for(int i = 2; i<=n; i++){
            if(n%i==0){
                ans.push_back(i);
                while(n && n%i==0){
                    n = n/i;
                }
            }
        }
        return ans;
    }
};