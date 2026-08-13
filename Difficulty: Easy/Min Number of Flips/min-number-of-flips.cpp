class Solution {
  public:
    int minFlips(string& s) {
        // code here
        int n = s.size(),cnt = 0;
        for(int i = 0; i<n; i++){
            if(i%2==0 && s[i]=='1') cnt++;
            else if(i%2!=0 && s[i]=='0') cnt++;
        }
        return min(cnt,n-cnt);
    }
};
