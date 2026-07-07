class Solution {
  public:
  
    int mod = 1e3;
  
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        q.push({0,start});
        vector<int> dist(1000,1e9);
        dist[start] = 0;
        while(!q.empty()){
            int distance = q.front().first,node = q.front().second;
            q.pop();
            for(auto it: arr){
                int newNode = (1LL*node*it)%mod;
                // if(newNode>end) continue;
                if(distance+1<dist[newNode]){
                    dist[newNode] = distance+1;
                    q.push({dist[newNode],newNode});
                }
            }
        }
        return dist[end]==1e9?-1:dist[end];
    }
};