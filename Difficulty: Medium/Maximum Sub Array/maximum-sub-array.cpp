class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = 0,j = 0,sum = 0,maxSum=0,maxLen = 0,start = -1;
        while(j<n){
            if(arr[j]<0){
                sum = 0;
                j++;
                i = j;
            }
            else{
                sum += arr[j];
                if(sum>maxSum){
                    maxSum = sum;
                    maxLen = j-i+1;   
                    start = i;
                }
                else if(sum==maxSum && j-i+1>maxLen){
                    maxLen = j-i+1;
                    start = i;
                }
                j++;
            }
        }
        if(start==-1) return {-1};
        vector<int> a;
        i = start;
        while(maxLen){
            a.push_back(arr[i]);
            i++;
            maxLen--;
        }
        return a;
    }
};