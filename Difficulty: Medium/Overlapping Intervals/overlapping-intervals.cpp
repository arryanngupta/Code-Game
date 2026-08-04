class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> v;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            int c = arr[i][0],d = arr[i][1];
            if(v.empty()){
                v.push_back({c,d});
            }
            else{
                int a = v.back()[0],b = v.back()[1];
                if((d>=a && d<=b) || (b>=c && b<=d)){
                    v.back()[0] = min(a,c);
                    v.back()[1] = max(b,d);
                }
                else{
                    v.push_back({c,d});
                }
            }
        }
        return v;
    }
};