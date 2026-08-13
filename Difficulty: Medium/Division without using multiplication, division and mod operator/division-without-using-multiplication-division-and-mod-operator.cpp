class Solution {
  public:
    int divide(int a, int b) {
        // code here
        long long ans = 0;
        int a1 = a,b1 = b;
        a = abs(a);
        b = abs(b);
        while(a>=b){
            int bit = 0,val = b;
            while((b*(1<<bit))<=a){
                bit++;
            }
            bit--;
            a -= (b*(1<<bit));
            ans += (1<<bit);
        }
        if((a1<0&& b1>=0) || (a1>=0 && b1<0)){
            ans *= -1;
            if(ans<INT_MIN) ans = INT_MIN;
        }
        return (int)ans;
    }
};