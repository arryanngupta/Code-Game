class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<int> freq(26,0),inDeg(26,0);
        int n = words.size();
        if(n==1){
            for(auto it: words[0]){
                freq[it-'a']=1;
            }
            string ans = "";
            for(int i = 0; i<26; i++){
                if(freq[i]) ans += char('a'+i);
            }
            return ans;
        }
        vector<vector<int>> adjList(26);
        for(int i = 0; i<n-1; i++){
            string a = words[i];
            string b = words[i+1];
            int len1 = a.size(),len2 = b.size();
            int j = 0,k = 0;
            while(j<len1 && k<len2 && a[j]==b[k]){
                freq[a[j]-'a']=freq[b[k]-'a']=1;
                j++;
                k++;
            }
            if(k==len2 && j<len1) return "";
            if(j<len1){
                freq[a[j]-'a'] = freq[b[k]-'a']=1;
                adjList[a[j]-'a'].push_back(b[k]-'a');
                inDeg[b[k]-'a']++;
            }
            while(j<len1){
                freq[a[j]-'a']=1;
                j++;
            }
            while(k<len2) {
                freq[b[k]-'a']=1;
                k++;
            }
        }
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i<26; i++){
            if(freq[i]) cnt++;
            if(freq[i] && inDeg[i]==0) q.push(i);
        }
        string ans = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += (char)('a'+node);
            for(auto it: adjList[node]){
                inDeg[it]--;
                if(inDeg[it]==0) q.push(it);
            }
        }
        if(ans.size()==cnt) return ans;
        return "";
    }
};