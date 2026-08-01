class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int i = 0,sum = 0,maxi = 0;
        while(i<n){
            sum += arr[i];
            if(mpp.count(sum-k)) maxi = max(maxi,i-mpp[sum-k]);
            if(!mpp.count(sum)) mpp[sum] = i;
            i++;
        }
        return maxi;
    }
};