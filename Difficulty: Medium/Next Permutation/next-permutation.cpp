class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n==1) return;
        int idx = n-2;
        while(idx>=0 && arr[idx]>=arr[idx+1]){
            idx--;
        }
        if(idx==-1){
            reverse(arr.begin(),arr.end());
        }
        else{
            int i = n-1;
            while(arr[i]<=arr[idx]) i--;
            swap(arr[i],arr[idx]);
            reverse(arr.begin()+idx+1,arr.end());
        }
    }
};