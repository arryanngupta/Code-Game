
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int x){
        prev = next = NULL;
        data = x;
    }
};

class LFUCache {
  public:
    set<pair<int,Node*>> st;
    unordered_map<int,pair<int,Node*>> mpp;
    unordered_map<int,int> mpp2;
    int capacity;
    Node* head;
    Node* tail;
    int cnt;
    LFUCache(int cap) {
        // code here
        head = tail = NULL;
        capacity = cap;
        cnt = 0;
    }

    int get(int key) {
        // code here
        if(!mpp.count(key)) return -1;
        Node* node = mpp[key].second;
            int freq = mpp[key].first;
            st.erase(mpp[key]);
            mpp[key].first++;
            st.insert({mpp[key].first,node});
            if(head==node) return mpp2[key];
            if(node==tail) tail = tail->prev;
            if(node->prev) node->prev->next = node->next;
            if(node->next) node->next->prev = node->prev;
            node->next = head;
            head->prev = node;
            head = node;
            return mpp2[key];
    }

        
    void put(int key, int value) {
        // code here
        if(capacity==0) return ;
        if(mpp.count(key)){
            Node* node = mpp[key].second;
            int freq = mpp[key].first;
            st.erase(mpp[key]);
            mpp2[key] = value;
            mpp[key].first++;
            st.insert({mpp[key].first,node});
            if(head==node) return ;
            if(node==tail) tail = tail->next;
            if(node->prev) node->prev->next = node->next;
            if(node->next) node->next->prev = node->prev;
            node->next = head;
            head->prev = node;
            head = node;
        }
        else{
            if(cnt>=capacity){
                Node* delNode;
                int freq = st.begin()->first;
                Node* node = head;
                while(node){
                    if(mpp[node->data].first==freq){
                        delNode = node;
                    }
                    node = node->next;
                }
                st.erase({freq,delNode});
                mpp.erase(delNode->data);
                mpp2.erase(delNode->data);
                if(delNode==head){
                    head = head->next;
                    if(head) head->prev = NULL;
                }
                if(delNode==tail){
                    tail = tail->prev;
                    if(tail) tail->next = NULL;
                }
                if(delNode->prev) delNode->prev->next = delNode->next;
                if(delNode->next) delNode->next->prev = delNode->prev;
                cnt--;
                delete delNode;
            }
            Node* newNode = new Node(key);
            if(cnt==0){
                head = tail = newNode;
            }
            else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            cnt++;
            mpp2[key] = value;
            mpp[key] = {1,newNode};
            st.insert({1,newNode});
        }
    }
};
