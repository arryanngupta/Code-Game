class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<vector<int>> a(n);
        for(int i = 0; i<n; i++){
            a[i] = {start[i],end[i]};
        }
        sort(a.begin(),a.end());
        int cnt = 0;
        for(int i = 0; i<n; i++){
            int s = a[i][0],e = a[i][1];
            if(pq.empty() || pq.top()>s){
                cnt++;
                pq.push(e);   
            }
            else{
                pq.pop();
                pq.push(e);
            }
        }
        return cnt;
    }
};
