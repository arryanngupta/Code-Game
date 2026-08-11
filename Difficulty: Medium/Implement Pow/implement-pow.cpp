class Solution {
  public:
    double power(double b, int e) {
        // code here
        if(e==0) return 1;
        double half = power(b,abs(e)/2);
        double total = half*half;
        if(abs(e)%2!=0) total *= b;
        if(e<0) return 1/total;
        return total;
    }
};