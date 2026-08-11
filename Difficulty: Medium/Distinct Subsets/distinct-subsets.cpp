class Solution {
  public:
    
    set<vector<int>> ans;
    
    void recFind(int idx,vector<int> a,vector<int>& arr,int n){
        if(idx>=n){
            sort(a.begin(),a.end());
            ans.insert(a);
            return ;
        }
        a.push_back(arr[idx]);
        recFind(idx+1,a,arr,n);
        a.pop_back();
        recFind(idx+1,a,arr,n);
    }
  
    vector<vector<int>> findSubsets(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> a;
        recFind(0,a,arr,n);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};