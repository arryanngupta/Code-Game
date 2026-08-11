class Solution {
  public:
  
    vector<vector<int>> ans;
    
    void recFind(int idx,vector<int> a,vector<int>& arr,int n){
        if(idx>=n){
            ans.push_back(a);
            return ;
        }
        a.push_back(arr[idx]);
        recFind(idx+1,a,arr,n);
        a.pop_back();
        recFind(idx+1,a,arr,n);
    }
  
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> a;
        recFind(0,a,arr,n);
        return ans;
    }
};