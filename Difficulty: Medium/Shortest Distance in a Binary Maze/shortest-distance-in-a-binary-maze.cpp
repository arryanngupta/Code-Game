class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        int n = mat.size(),m = mat[0].size();
        if(mat[src[0]][src[1]]==0 || mat[dest[0]][dest[1]]==0) return -1;
        queue<pair<int,pair<int,int>> > q;
        q.push({0,{src[0],src[1]}});
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[src[0]][src[1]]=0;
        while(!q.empty()){
            int distance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    if((i==0 && j==0)||(i!=0 && j!=0)) continue;
                    int nr = i+row;
                    int nc = j+col;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc] 
                    && distance+1<dist[nr][nc]){
                        dist[nr][nc]=distance+1;
                        q.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return dist[dest[0]][dest[1]]==1e9?-1:dist[dest[0]][dest[1]];
    }
};
