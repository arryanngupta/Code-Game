class Solution {
  public:
  
    vector<int> l,r;
  
    void recFind(int idx,int sum,vector<int> &arr,int n,int flag){
        if(idx==n){
            if(flag==0) l.push_back(sum);
            else r.push_back(sum);
            return;
        }
        recFind(idx+1,sum+arr[idx],arr,n,flag);
        recFind(idx+1,sum,arr,n,flag);
    }
  
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        recFind(0,0,arr,n/2,0);
        recFind(n/2,0,arr,n,1);
        unordered_map<int,int> mpp;
        int ans = 0;
        for(auto it: r){
            mpp[it]++;
        }
        for(auto it: l){
            int rem = k-it;
            ans += mpp[rem];
        }
        return ans;
    }
};