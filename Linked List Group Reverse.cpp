class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node *temp=head;
        Node *dum=head;
        int c=0;
        stack<int> st;
        
        while(temp!=NULL)
        {
            while(c<k && temp!=NULL)
            {
                st.push(temp->data);
                temp=temp->next;
                c++;
            }
            while(!st.empty())
            {
                dum->data=st.top();
                dum=dum->next;
                st.pop();
                
            }
            c=0;
        }
        return head;
    }
};
