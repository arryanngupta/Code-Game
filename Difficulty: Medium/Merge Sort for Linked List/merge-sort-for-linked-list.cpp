/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
  
    Node* merge(Node* left,Node* right){
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        while(left && right){
            if(left->data<=right->data){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        if(left) temp->next = left;
        else temp->next = right;
        return dummyNode->next;
    }
  
    Node* sort(Node* node){
        if(!node || !node->next) return node;
        Node* fast = node;
        Node* slow = node;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        Node* right = slow->next;
        slow->next = NULL;
        Node* left = sort(node);
        right = sort(right);
        return merge(left,right);
    }
  
  
    Node* mergeSort(Node* head) {
        // code here
        return sort(head);
    }
};