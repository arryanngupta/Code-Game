class Solution {
  public:
  
    vector<vector<int>> dp;
  
    bool recFind(int i,int sum,vector<int>& arr,int n){
        if(sum==0) return true;
        if(i==n) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take = false,notTake = false;
        if(sum>=arr[i]){
            take = recFind(i+1,sum-arr[i],arr,n);
        }
        notTake = recFind(i+1,sum,arr,n);
        return dp[i][sum]=(take||notTake);
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        dp.resize(n,vector<int> (sum+1,-1));
        return recFind(0,sum,arr,n);
    }
};