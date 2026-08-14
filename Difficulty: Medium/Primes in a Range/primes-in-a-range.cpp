class Solution {
  public:
  
    vector<int> primes;
  
    vector<int> primeRange(int l, int r) {
        // code here
        primes.resize(r+1,1);
        primes[0] = primes[1] = 0;
        for(int i = 2; i*i<=r; i++){
            if(primes[i]==1){
                for(int j = i*i; j<=r; j+=i){
                    primes[j] = 0;
                }
            }
        }
        vector<int> ans;
        for(int i = l; i<=r; i++) if(primes[i]) ans.push_back(i);
        return ans;
    }
};