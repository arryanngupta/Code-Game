class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int i = 0,sum = 0,maxi = -1e9,j = 0;
        while(j<n){
            sum += arr[j];
            maxi = max(maxi,sum);
            while(sum<0){
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return maxi;
    }
};