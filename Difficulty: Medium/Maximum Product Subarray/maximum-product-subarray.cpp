class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int prod = 1,maxi = -1e9,n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i]==0){
                maxi = max(maxi,0);
                prod = 1;
                continue;
            }
            prod *= arr[i];
            maxi = max(maxi,prod);
        }
        prod = 1;
        for(int i = n-1; i>=0; i--){
            if(arr[i]==0){
                maxi = max(maxi,0);
                prod = 1;
                continue;
            }
            prod *= arr[i];
            maxi = max(maxi,prod);
        }
        return maxi;
    }
};