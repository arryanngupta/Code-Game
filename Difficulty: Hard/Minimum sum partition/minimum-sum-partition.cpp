class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,int sum,int target,vector<int>& arr,int n){
        if(sum==target || idx==n) return sum;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int take = 0,notTake = 0;
        if(target>=sum+arr[idx]){
            take = recFind(idx+1,sum+arr[idx],target,arr,n);
        }
        notTake = recFind(idx+1,sum,target,arr,n);
        return dp[idx][sum]=max(take,notTake);
    }
  
    int minDifference(vector<int>& arr) {
        // code here
        int sum = 0;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        dp.resize(n,vector<int> (sum/2,-1));
        int res = recFind(0,0,sum/2,arr,n);
        if(sum%2==0){
            return (res==(sum/2))?0:sum-2*res;
        }
        return (res==(sum/2))?1:sum-2*res;
    }
};