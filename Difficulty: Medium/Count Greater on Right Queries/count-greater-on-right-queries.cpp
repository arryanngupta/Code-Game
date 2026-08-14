class Solution {
  public:
  
    vector<int> ans;  
    
    void merge(int p,int q,int r,vector<pair<int,int>> &v){
        vector<pair<int,int>> a(r-p+1);
        int i = p,j = q+1,idx = 0;
        while(i<=q && j<=r){
            if(v[i].first<v[j].first){
                ans[v[i].second] += r-j+1;
                a[idx++] = v[i++];
            }
            else{
                a[idx++] = v[j++];
            }
        }
        while(i<=q) a[idx++] = v[i++];
        while(j<=r) a[idx++] = v[j++];
        for(int i = 0; i<a.size(); i++) v[i+p] = a[i];
    }
    
    void mergeSort(int i,int j,vector<pair<int,int>> &v){
        if(i<j){
            int mid = (i+j)/2;
            mergeSort(i,mid,v);
            mergeSort(mid+1,j,v);
            merge(i,mid,j,v);
        }
    }
    
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {
        // code here
        int n = arr.size();
        ans.resize(n);
        vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++){
            v[i] = {arr[i],i};
        }
        mergeSort(0,n-1,v);
        vector<int> res;
        for(auto it: indices){
            res.push_back(ans[it]);
        }
        return res;
    }
};