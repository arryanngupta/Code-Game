class Solution {
  public:
  
    unordered<vector<int>> ans;
    
    void recFind(int idx,vector<int> a,vector<int> &arr, int target,int n){
        if(target==0){
            ans.push_back(a);
            return ;
        }
        if(idx>=n){
            return ;
        }
        if(arr[idx]<=target){
            a.push_back(arr[idx]);
            recFind(idx,a,arr,target-arr[idx],n);
            a.pop_back();
        }
        recFind(idx+1,a,arr,target,n);
    }   
  
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        vector<int> a;
        recFind(0,a,arr,target,n);
        return ans;
    }
};