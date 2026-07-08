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
    vector<vector<string>> accMerge(vector<vector<string>>& arr) {
        // code here
        int n = arr.size();
        DisjointSets ds(n);
        unordered_map<string,int> mpp;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<arr[i].size(); j++){
                string s = arr[i][j];
                if(mpp.find(s)==mpp.end()){
                    mpp[s] = i;
                }
                else{
                    ds.findUnionByRank(mpp[s],i);
                }
            }
        }
        unordered_map<int,set<string>> mpp2;
        for(auto it: mpp){
            int ulp = ds.findUPar(it.second);
            mpp2[ulp].insert(it.first);
        }
        vector<vector<string>> ans;
        for(auto it: mpp2){
            int idx = it.first;
            vector<string> temp;
            temp.push_back(arr[idx][0]);
            for(auto it1: it.second) temp.push_back(it1);
            ans.push_back(temp);
        }
        return ans;
    }
};
