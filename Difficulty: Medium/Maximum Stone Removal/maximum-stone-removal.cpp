class DisjointSets{
    vector<int> parent,rank;
    public:
        DisjointSets(int n){
            rank.resize(n+1,0); // n+1 covers both 0 and 1 based indexing.
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

        void findUnionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return; // already in a same component
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        int n = stones.size();
        int maxRow = 0,maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        int len = maxRow+1+maxCol+1;
        unordered_set<int> st;
        DisjointSets ds(len);
        for(auto it: stones){
            int u = it[0],v = maxRow+1+it[1];
            ds.findUnionByRank(u,v);
            st.insert(u);
            st.insert(v);
        }
        unordered_map<int,int> mpp;
        for(auto it: st){
            int val = ds.findUPar(it);
            mpp[val]++;
        }
        int components = mpp.size();
        return (n-components);
    }
};