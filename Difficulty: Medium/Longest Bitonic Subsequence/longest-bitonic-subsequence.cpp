class Solution {
  public:
  
    vector<int> solve(int n,vector<int> &nums){
        vector<int> dp(n,1);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        return dp;
    }
  
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dp1 = solve(n,nums);
        reverse(nums.begin(),nums.end());
        vector<int> dp2 = solve(n,nums);
        int maxi = 0;
        for(int i = 0; i<n; i++){
            if(dp1[i]>1 && dp2[n-i-1]>1){
                maxi = max(maxi,dp1[i]+dp2[n-i-1]-1);
            }
        }
        return maxi;
    }
};
