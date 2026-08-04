class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int i = 0,sum = 0,maxi = 0;
        while(i<n){
            sum += arr[i];
            if(mpp.count(sum)) maxi = max(maxi,i-mpp[sum]);
            if(!mpp.count(sum)) mpp[sum] = i;
            i++;
        }
        return maxi;
    }
};