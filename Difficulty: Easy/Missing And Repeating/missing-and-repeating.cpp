class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size(),Xor = 0,actXor = 0;
        for(int i = 0; i<n; i++){
            actXor ^= arr[i];
            Xor ^= (i+1);
        }
        int a = actXor^Xor;
        int bit = 0;
        while(a){
            if(a%2!=0){
                break;
            }
            a = a/2;
            bit++;
        }
        int z = 0,o = 0;
        for(int i = 0; i<n; i++){
            if((1<<bit)&arr[i]) o ^= arr[i];
            else z ^= arr[i];
            if((1<<bit)&(i+1)) o ^= (i+1);
            else z ^= (i+1);
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]==z){
                return {z,o};
            }
        }
        return {o,z};
    }
};
