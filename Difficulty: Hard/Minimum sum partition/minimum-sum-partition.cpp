class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,int sum,int target,vector<int>& arr,int n){
        if(sum==target || idx==n) return sum;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int take = 0,notTake = 0;
        if(sum+arr[idx]<=target){
            take = recFind(idx+1,sum+arr[idx],target,arr,n);
        }
        notTake = recFind(idx+1,sum,target,arr,n);
        return dp[idx][sum]=max(take,notTake);
    }
  
    int minDifference(vector<int>& arr) {
        // code here
        int n = arr.size();
        int s = 0;
        for(auto it: arr) s += it;
        dp.resize(n,vector<int> (s,-1));
        int s1 = recFind(0,0,s/2,arr,n);
        return s-2*s1;
    }
};