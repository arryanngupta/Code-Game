class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int n = s.size();
        int idx = 0;
        while(idx<n && s[idx]== ' '){
            idx++;
        }
        int sign = 1;
        if(s[idx]=='-'){
            sign = 0;
            idx++;
        }
        else if(s[idx]=='+') idx++;
        while(idx<n && s[idx]== '0'){
            idx++;
        }
        if(idx==n) return 0;
        long long ans = 0;
        while(idx<n && s[idx]>='0' && s[idx]<='9'){
            int digit = s[idx]-'0';
            ans = ans*10+digit;
            if(sign){
                if(ans>INT_MAX) return INT_MAX;
            }
            else{
                if(-1LL*ans<INT_MIN) return INT_MIN;
            }
            idx++;
        }
        if(sign) return (int)ans;
        ans *= -1;
        return (int)ans;
    }
};
