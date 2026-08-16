class Solution {
  public:
  
    vector<int> pse,nse;

    void find1(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        pse.resize(n);
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
        nse.resize(n);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
    }
    
    int find(vector<int> &arr) {
        // code here
        // formula :- (nse-pse-1)*arr[i];
        int n = arr.size();
        find1(arr);
        find2(arr);
        int maxi = 0;
        for(int i = 0; i<n; i++){
            maxi = max(maxi,(nse[i]-pse[i]-1) * arr[i]);
        }
        return maxi;
    }
  
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(),m = mat[0].size();
        vector<int> a(m);
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]) a[j] += mat[i][j];
                else a[j] = 0;
            }
            maxi = max(maxi,find(a));
        }
        return maxi;
    }
};