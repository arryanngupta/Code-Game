class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = n-1; i>=0; i--) st.push(arr[i]);
        int i = n-1;
        while(i>=0){
            while(!st.empty() && st.top()<=arr[i]) st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i] = st.top();
            st.push(arr[i]);
            i--;
        }
        return ans;
    }
};