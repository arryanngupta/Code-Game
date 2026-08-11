class Solution {
  public:
  
    void insert(stack<int> &st,int element){
        if(element==-1) return ;
        stack<int> st2;
        while(!st.empty() && st.top()>element){
            st2.push(st.top());
            st.pop();
        }
        st.push(element);
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
    }
  
    void recFind(stack<int> &st,int element){
        if(st.empty()){
            if(element!=-1) st.push(element);
            return;
        }
        int ele = st.top();
        st.pop();
        recFind(st,ele);
        insert(st,element);
    }
  
    void sortStack(stack<int> &st) {
        // code here
        recFind(st,-1);
    }
};
