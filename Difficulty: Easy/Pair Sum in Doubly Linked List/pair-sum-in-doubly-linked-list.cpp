/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        // code here
        Node* left = head;
        vector<vector<int>> ans;
        Node* right = head;
        while(right->next){
            right = right->next;
        }
        while(left->data<right->data){
            if(left->data+right->data<target){
                left = left->next;
            }
            else if(left->data+right->data>target){
                right = right->prev;
            }
            else{
                ans.push_back({left->data,right->data});
                left = left->next;
                right = right->prev;
            }
        }
        return ans;
    }
};