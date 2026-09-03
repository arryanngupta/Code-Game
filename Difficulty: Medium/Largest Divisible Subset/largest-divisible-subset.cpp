class Solution {
  public:
  
  
    vector<int> largestSubset(vector<int>& arr) {
        // code here
        int n = arr.size(),idx = -1;
        sort(arr.begin(),arr.end());
        vector<vector<int>> dp(n);
        vector<int> maxi;
        for(int i = 0; i<n; i++){
            dp[i].push_back(arr[i]);
            int j = i-1;
            while(j>=0){
                if(arr[i]%arr[j]==0){
                    vector<int> a = dp[j];
                    a.push_back(arr[i]);
                    if(a.size()>dp[i].size() || (a.size()==dp[i].size() && a>dp[i])){
                        dp[i] = a;
                    }
                }
                j--;
            }
            if(dp[i].size()>maxi.size() || (dp[i].size()==maxi.size() && dp[i]>maxi)){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};