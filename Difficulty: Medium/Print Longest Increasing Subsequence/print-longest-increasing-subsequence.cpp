class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n,1);
        unordered_map<int,int> mpp;
        int maxi = 0,maxIdx = -1;
        for(int i = 0; i<n; i++){
            if(!mpp.count(i)) mpp[i] = i;
            int j = i-1;
            while(j>=0){
                if(arr[j]<arr[i]){
                    if(dp[j]+1>=dp[i]){
                        mpp[i] = j;
                        dp[i] = dp[j]+1;
                    }
                }
                j--;
            }
            if(dp[i]>maxi){
                maxIdx = i;
                maxi = dp[i];
            }
        }
        if(maxi==0) return {};
        vector<int> ans(maxi);
        int idx = maxIdx;
        while(mpp[idx]!=idx){
            ans[maxi-1] = arr[idx];
            maxi--;
            idx = mpp[idx];
        }
        ans[0] = arr[idx];
        return ans;
    }
};