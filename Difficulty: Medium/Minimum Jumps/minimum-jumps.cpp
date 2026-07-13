class Solution {
  public:
  
    // vector<int> dp;
  
    // int recFind(int idx,vector<int>& arr,int n){
    //     if(idx>=n-1) return 0;
    //     if(dp[idx]!=-1) return dp[idx];
    //     int ans = 1e9;
    //     for(int i = 1; i<=arr[idx]; i++){
    //         ans = min(ans,1+recFind(idx+i,arr,n));
    //     }
    //     return dp[idx]=ans;
    // }
  
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        // dp.resize(n,-1);
        // int ans = recFind(0,arr,n);
        // return ans>=1e9?-1:ans;
        
        
        int i = 0,maxi = 0,ans = 0,maxEnd=0;
        while(i<n){
            if(i>maxEnd) return -1;
            if(maxEnd>maxi){
                maxi = maxEnd;
                ans++;
            }
            if(maxi>=n-1) return ans;
            int flag = 0;
            while(i<=maxi){
                flag = 1;
                maxEnd = max(maxEnd,i+arr[i]);
                i++;
            }
            if(flag==0) i++;
        }
        return ans;
    }
};
