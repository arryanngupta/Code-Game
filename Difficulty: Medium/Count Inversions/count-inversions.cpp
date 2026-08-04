class Solution {
  public:
  
    int ans;
    
    void merge(int p,int q,int r,vector<int> &arr,int n){
        vector<int> a;
        int low = p,high = q+1;
        while(low<=q && high<=r){
            if(arr[low]<=arr[high]){
                a.push_back(arr[low]);
                low++;
            }
            else{
                ans += q-low+1;
                a.push_back(arr[high]);
                high++;
            }
        }
        while(low<=q){
            a.push_back(arr[low]);
            low++;
        }
        while(high<=r){
            a.push_back(arr[high]);
            high++;
        }
        for(int i = 0; i<a.size(); i++){
            arr[i+p] = a[i];
        }
    }
    
    void mergeSort(int i,int j,vector<int> &arr,int n){
        if(i<j){
            int mid = (i+j)/2;
            mergeSort(i,mid,arr,n);
            mergeSort(mid+1,j,arr,n);
            merge(i,mid,j,arr,n);
        }
    }
  
    int inversionCount(vector<int> &arr) {
        // code here
        ans = 0;
        int n = arr.size();
        mergeSort(0,n-1,arr,n);
        return ans;
    }
};