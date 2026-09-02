class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n==1) return 0;
        sort(arr.begin(),arr.end());
        int ans = arr[n-1]-arr[0];
        int mini = arr[0]+k,maxi = arr[n-1]-k;
        for(int i = 0;i<n-1; i++){
            maxi = max(arr[i]+k,arr[n-1]-k);
            mini = min(arr[i+1]-k,arr[0]+k);
            ans = min(ans,maxi-mini);
        }
        return ans;
    }
};