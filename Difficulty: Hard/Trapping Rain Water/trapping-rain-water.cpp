class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> suff(n);
        int maxi = -1;
        for(int i = n-1; i>=0; i--){
            suff[i] = maxi;
            maxi = max(maxi,arr[i]);
        }
        maxi = -1;
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans += max(0,min(maxi,suff[i])-arr[i]);
            maxi = max(maxi,arr[i]);
        }
        return ans;
    }
};