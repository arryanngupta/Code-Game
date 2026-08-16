class Solution {
  public:
  
    vector<int> pse,nse;
    
    void find1(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
    }
    
    void find2(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
    }
  
    int getMaxArea(vector<int> &arr) {
        // code here
        // formula :- (nse-pse-1)*arr[i];
        int n = arr.size();
        pse.resize(n);
        nse.resize(n);
        find1(arr);
        find2(arr);
        int maxi = 0;
        for(int i = 0; i<n; i++){
            maxi = max(maxi,(nse[i]-pse[i]-1) * arr[i]);
        }
        return maxi;
    }
};
