class Solution {
  public:
  
    bool recFind(int idx,vector<int>& arr, int k){
        if(k==0) return true;
        if(idx>=arr.size()) return false;
        if(arr[idx]<=k){
            if(recFind(idx+1,arr,k-arr[idx])) return true;
        }
        if(recFind(idx+1,arr,k)) return true;   
    }
  
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
        return recFind(0,arr,k);
    }
};