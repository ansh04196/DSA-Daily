class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        if(!head || !head->next)
            return NULL;
        Node* slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                Node* temp=head;
                while(temp)
                {
                    if(temp==slow)
                        return slow;
                    temp=temp->next;
                    slow=slow->next;
                }
            }
        }
        return NULL;
    }
};
