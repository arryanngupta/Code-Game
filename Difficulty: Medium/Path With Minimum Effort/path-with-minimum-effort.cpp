class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(),m = mat[0].size();
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[0][0]=0;
        while(!pq.empty()){
            int maxi = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (maxi > dist[row][col]) continue;
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    if((i==0 && j==0)||(i!=0 && j!=0)) continue;
                    int nr = i+row;
                    int nc = j+col;
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        int cost = max(maxi,abs(mat[row][col]-mat[nr][nc]));
                        if(cost<dist[nr][nc]){
                            dist[nr][nc]=cost;
                            pq.push({dist[nr][nc],{nr,nc}});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
