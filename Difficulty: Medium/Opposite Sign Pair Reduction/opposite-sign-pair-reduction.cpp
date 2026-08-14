class Solution {
  public:
  
    bool isSameSign(int a,int b){
        return ((a>=0 && b>=0) || (a<=0 && b<=0));
    }
  
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && !isSameSign(arr[i],st.top()) 
            && abs(st.top())<abs(arr[i])) st.pop();
            if(st.empty() || isSameSign(arr[i],st.top())) st.push(arr[i]);
            else if(abs(st.top())==abs(arr[i])) st.pop();
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};