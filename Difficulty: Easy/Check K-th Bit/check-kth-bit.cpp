class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        return ((1<<k)^n);
    }
};