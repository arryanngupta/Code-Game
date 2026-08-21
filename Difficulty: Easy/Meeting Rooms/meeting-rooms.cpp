class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        int e = 0;
        sort(arr.begin(),arr.end());
        for(auto it: arr){
            if(e>it[0]) return false;
            e = it[1];
        }
        return true;
    }
};