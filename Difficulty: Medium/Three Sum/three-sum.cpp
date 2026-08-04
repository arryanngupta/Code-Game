class Solution {
  public:
    vector<vector<int>> triplets(vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int i = 0,j = i+1,k = n-1,target = 0;
        set<vector<int>> st;
        while(i<n){
            j = i+1,k = n-1;
            while(j<k){
                if(arr[i]+arr[j]+arr[k]<target) j++;
                else if(arr[i]+arr[j]+arr[k]>target) k--;
                else{
                    st.insert({arr[i],arr[j],arr[k]});
                    j++;
                    k--;
                }
            }
            i++;
        }
        return vector<vector<int>> (st.begin(),st.end());
    }
};
