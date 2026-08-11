class Solution {
  public:
  
    void insert(stack<int> &st,int element){
        if(element == -1) return ;
        if(st.empty()){
            st.push(element);
            return ;
        }
        int ele = st.top();
        st.pop();
        insert(st,element);
        st.push(ele);
    }
  
    void recFind(stack<int> &st,int element){
        if(st.empty()){
            if(element == -1) return ;
            st.push(element);
            return ;
        }
        int ele = st.top();
        st.pop();
        recFind(st,ele);
        insert(st,element);
    }
  
    void reverseStack(stack<int> &st) {
        // code here
        recFind(st,-1);
    }
};