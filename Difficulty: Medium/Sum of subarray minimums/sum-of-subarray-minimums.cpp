class Solution {
  public:
  
    vector<int> left,right;
  
    void nse(vector<int> &arr){
        int n = arr.size();
        right.resize(n);
        stack<int> st;
        int i = n-1;
        while(i>=0){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(i);
            i--;
        }
    }
    
    void pse(vector<int> &arr){
        int n = arr.size(),i = 0;
        left.resize(n);
        stack<int> st;
        while(i<n){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
            i++;
        }
    }
  
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        nse(arr);
        pse(arr);
        int ans = 0;
        for(int i = 0; i<n; i++){
            int l = left[i],r = right[i];
            ans += 1LL*arr[i]*(i-l)*(r-i);
        }
        return ans;
    }
};