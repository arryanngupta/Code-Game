class Solution {
  public:
  
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans;
        for(int i = 0; i<n; i++){
            int lb = lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            if(lb==ans.size()) ans.push_back(arr[i]);
            else ans[lb] = arr[i];
        }
        return ans.size();
    }
};