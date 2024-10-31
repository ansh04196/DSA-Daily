class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node * res = new Node();
        res->data = x;
        if(x<head->data)
        {
            res->prev = NULL;
            res->next = head;
            head->prev = res;
            head = res;
        }
        else
        {
            Node * curr = head;
            while(curr->next && curr->next->data < x)
            curr = curr->next;
            
            if(curr->next)
            {
                res->prev = curr;
                res->next = curr->next;
                curr->next->prev = res;
                curr->next = res;
            }
            else
            {
                res->next = NULL;
                res->prev = curr;
                curr->next = res;
            }
        }
        return head;
    }
};
