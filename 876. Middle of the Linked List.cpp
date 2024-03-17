/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int getLength(ListNode* head){
        int len=0;
        ListNode* temp=head;
    
    while(temp !=NULL){
        len++;
        temp= temp-> next;
    }
    return len;
  }
    ListNode* middleNode(ListNode* head) {
        int n= getLength(head);
        int position = n/2+1;
        int currPos = 1;
        ListNode*temp=head;
        while (currPos != position){
            currPos++;
            temp= temp->next;
        }
        return temp;
    }
}; 
