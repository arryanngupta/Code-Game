class Solution {
  public:
    int wordLadder(vector<string> &words, string &s, string &e) {
        // code here
        int n = words.size();
        unordered_map<string,vector<string>> mpp;
        int flag = 0;
        for(auto it: words){
            if(it==e) flag = 1;
            mpp[it].push_back("");
        }
        if(!flag) return 0;
        for(int i = 0; i<n; i++){
            string a = words[i];
            int len = a.size();
            for(int j = 0; j<len; j++){
                a = words[i];
                int c = a[j];
                for(char ch = 'a'; ch<='z'; ch++){
                    if(c==ch) continue;
                    a[j]= ch;
                    if(a!=words[i] && mpp.count(a)) mpp[words[i]].push_back(a);
                }
            }
        }
        if(!mpp.count(s)){
            for(int i = 0; i<n; i++){
                string a = words[i];
                int len = s.size();
                int k = 0,cnt= 0;
                while(k<len){
                    if(s[k]!=a[k]) cnt++;
                    k++;
                }
                if(cnt==1) mpp[s].push_back(a);
            }
        }
        queue<pair<int,string>> pq;
        pq.push({1,s});
        unordered_map<string,int> dist;
        dist[s] = 1;
        while(!pq.empty()){
            int distance = pq.front().first;
            string w = pq.front().second;
            pq.pop();
            if(distance>dist[w]) continue;
            for(auto it: mpp[w]){
                if(!dist.count(it)){
                    dist[it] = distance+1;
                    pq.push({dist[it],it});
                }
            }
        }
        if(!dist.count(e)) return 0;
        return dist[e];
    }
};