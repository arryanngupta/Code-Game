class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        set<pair<int,int>> st;
        int n = arr.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            if(mpp.count(-1*arr[i])) st.insert(make_pair(-1*abs(arr[i]),abs(arr[i])));
            mpp[arr[i]] = 1;
        }
        vector<vector<int>> ans;
        for(auto it: st) ans.push_back({it.first,it.second});
        return ans;
    }
};