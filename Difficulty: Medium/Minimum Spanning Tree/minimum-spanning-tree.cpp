class DisjointSets{
    vector<int> parent,size;
    public:
        DisjointSets(int n){
            size.resize(n+1,1); // n+1 covers both 0 and 1 based indexing.
            parent.resize(n+1);
            for(int i = 0; i<n; i++){
                parent[i] = i;
            }
        }
        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUPar(parent[node]);
        }

        void findUnionBySize(int ulp_u, int ulp_v){
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > pq;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            pq.push({wt,{u,v}});
        }
        DisjointSets ds(V);
        int sum = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            int ulp_u = ds.findUPar(u);
            int ulp_v = ds.findUPar(v);
            if(ulp_u != ulp_v){
                ds.findUnionBySize(ulp_u,ulp_v);
                sum += wt;
            }
        }
        return sum;
    }
};