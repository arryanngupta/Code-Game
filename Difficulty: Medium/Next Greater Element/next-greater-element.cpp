class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = n-1;
        stack<int> st;
        vector<int> ans(n);
        ans[n-1] = -1;
        st.push(arr[n-1]);
        while(i>=0){
            while(!st.empty() && st.top()<=arr[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(arr[i]);
            i--;
        }
        return ans;
    }
};