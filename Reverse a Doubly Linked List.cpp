/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr = head;
        int l = 0 , r = 0;
        while(curr -> next != NULL){
            curr = curr -> next;
            r++;
        }
        
        Node* prevNode = curr;
        curr = head;
        while(l <= r){
            int temp = curr -> data;
            curr -> data = prevNode -> data;
            prevNode -> data = temp;
            curr = curr -> next;
            prevNode = prevNode -> prev;
            l++;
            r--;
        }
        return head;
    }
};
//GFG POTD solution for 03 September
