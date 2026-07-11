class Solution {
  public:
    
    vector<vector<vector<int>>> dp;
  
    int recFind(int idx,int flag,int cnt,vector<int> &arr,int n){
        if(idx==n || cnt==0) return 0;
        if(dp[idx][flag][cnt]!=-1) return dp[idx][flag][cnt];
        int take = -1e9,notTake = -1e9;
        if(flag==0){
            take = -arr[idx]+recFind(idx+1,1,cnt,arr,n);
        }
        else{
            take = arr[idx]+recFind(idx+1,0,cnt-1,arr,n);
        }
        notTake = recFind(idx+1,flag,cnt,arr,n);
        return dp[idx][flag][cnt]=max(take,notTake);
    }
  
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        dp.resize(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return recFind(0,0,k,prices,n);
    }
};