class Solution {
  public:
  
    unordered_map<int,string> mpp;
    vector<string> ans;
    
    void recFind(int idx,string curr,vector<int> &arr,int n){
        if(idx>=n){
            ans.push_back(curr);
            return ;
        }
        string str = mpp[arr[idx]];
        if(str.empty()) recFind(idx+1,curr,arr,n);
        string s = curr;
        for(auto it: str){
            s.push_back(it);
            recFind(idx+1,s,arr,n);
            s.pop_back();
        }
    }
  
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        int n = arr.size();
        mpp[0] = mpp[1] = "";
        int i = 2;
        char ch = 'a';
        string s = "";
        while(i<=9){
            s += ch;
            ch++;
            if(i==7 || i==9){
                if(s.size()==4){
                    mpp[i] = s;
                    i++;
                    s = "";
                }
            }
            else{
                if(s.size()==3){
                    mpp[i] = s;
                    i++;
                    s = "";
                }
            }
        }
        ans.clear();
        recFind(0,"",arr,n);
        return ans;
    }
};