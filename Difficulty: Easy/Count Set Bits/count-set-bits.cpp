class Solution {
  public:
    int setBits(int n) {
        // Code here
        int ans = 0;
        while(n){
            if(n%2!=0) ans++;
            n = n/2;
        }
        return ans;
    }
};