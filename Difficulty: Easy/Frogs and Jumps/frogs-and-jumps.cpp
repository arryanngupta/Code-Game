class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        sort(frogs,frogs+N);
        vector<int> a(leaves+1,0);
        for(int i = 0; i<N; i++){
            int k = frogs[i];
            if(k>leaves) break;
            if(a[k]) continue;
            for(int j = k; j<=leaves; j+=k){
                a[j]=1;
            }
        }
        int cnt = 0;
        for(int i = 1; i<=leaves; i++){
            if(a[i]==0) cnt++;
        }
        return cnt;
    }
};
