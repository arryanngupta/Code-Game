class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>> a(n);
        a[0].push_back(1);
        for(int i = 1; i<n; i++){
            a[i].resize(i+1);
            a[i][0] = 1;
            for(int j = 0; j<a[i-1].size()-1; j++){
                a[i][j+1]=(a[i-1][j]+a[i-1][j+1]);
            }
            a[i][i] = (1);
        }
        return a[n-1];
    }
};
