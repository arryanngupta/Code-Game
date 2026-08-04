class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int i = 0,n = arr.size(),j = n-1;
        while(i<j){
            if(arr[i]+arr[j]<target) i++;
            else if(arr[i]+arr[j]>target) j--;
            else return true;
        }
        return false;
    }
};