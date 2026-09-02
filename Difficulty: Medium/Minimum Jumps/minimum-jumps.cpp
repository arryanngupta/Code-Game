class Solution {
  public:
    
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int cnt = 0,maxi = 0,maxi2 = 0;
        int i = 0;
        while(i<n){
            if(i>maxi) return -1;
            if(i>maxi2){
                cnt++;
                maxi2 = maxi;
            }
            maxi = max(maxi,i+arr[i]);
            i++;
        }
        return cnt;
    }
};
