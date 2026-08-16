
class Node{
public:
    Node* prev;
    Node* next;
    int data;
    Node(int x){
        data = x;
        prev = next = NULL;
    }
};


class LRUCache {
  public:
    int capacity;
    unordered_map<int,Node*> mpp;
    unordered_map<int,int> mpp2;
    Node* head;
    Node* tail;
    int cnt;
    LRUCache(int cap) {
        // code here
        capacity = cap;
        cnt = 0;
        head = NULL;
        tail = NULL;
    }

    int get(int key) {
        if(mpp.find(key)==mpp.end())return -1;
        // code here
        Node* node = mpp[key];
        if(node==head) return mpp2[node->data];
            if(tail==node) tail = tail->prev;
            if(node->prev) node->prev->next = node->next;
            if(node->next) node->next->prev = node->prev;
            node->next = head;
            head->prev = node;
            head = node;
            return mpp2[key];
    }

        
    void put(int key, int value) {
        // code here
        if(mpp2.count(key)){
            Node* node = mpp[key];
            if(node==head){
                mpp2[key]=value;
                return ;
            }
            if(tail==node) tail = tail->prev;
            if(node->prev) node->prev->next = node->next;
            if(node->next) node->next->prev = node->prev;
            node->next = head;
            head->prev = node;
            head = node;
            mpp2[key] = value;
        }
        else{
            Node* newNode = new Node(key);
            if(cnt>=capacity){
                Node* node = tail;
                tail = tail->prev;
                if(tail) tail->next = NULL;
                mpp.erase(node->data);
                mpp2.erase(node->data);
                delete node;
                cnt--;
                if(cnt==0) head = tail;
            }
            mpp2[key] = value;
            cnt++;
            if(cnt==1) tail = newNode;
            newNode->next = head;
            if(head) head->prev = newNode;
            head = newNode;
            mpp[key] = head;
        }
    }
};