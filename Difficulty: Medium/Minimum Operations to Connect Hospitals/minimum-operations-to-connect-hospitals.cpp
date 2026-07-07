class DisjointSets{
public:
    vector<int> parent,rank;
    DisjointSets(int n){
        rank.resize(n);
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;
    }
    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void findUnionByRank(int u,int v){
        if(rank[u]>rank[v]){
            parent[v] = u;
        }
        else if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
};


class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        DisjointSets ds(V);
        int cnt = 0;
        for(auto it: edges){
            int u = it[0],v = it[1];
            int ulp_u = ds.findUPar(u),ulp_v = ds.findUPar(v);
            if(ulp_u==ulp_v) cnt++;
            else ds.findUnionByRank(ulp_u,ulp_v);
        }
        unordered_set<int> st;
        for(int i= 0; i<V;i++){
            st.insert(ds.findUPar(i));
        }
        if((st.size()-1)>cnt) return -1;
        return (st.size()-1);
    }
};
