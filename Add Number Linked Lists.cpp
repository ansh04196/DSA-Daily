class Solution
{
    public:
   struct Node * reverse(struct Node* first){
        Node *curr=first,*prev=NULL,*np;
        while(curr!=NULL){
            np=curr->next;
            curr->next=prev;
            prev=curr;
            curr=np;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {   Node *dumb=new Node(0);Node *dummy=dumb;
        // code here
        Node *n1=reverse(first);
        Node *n2=reverse(second);
        int c=0;
        while(n1!=NULL || n2 !=NULL || c){
            int sum=0;
            if(n1!=NULL){
                sum+=n1->data;n1=n1->next;
            }
             if(n2!=NULL){
                sum+=n2->data;n2=n2->next;
            }
             sum+=c;
             c=sum/10;
            // int base=sum%10;
            Node *node=new Node(sum%10);
            dummy->next=node;
            dummy=node;
            
        }
        Node *ans= reverse(dumb->next);
        if(ans->data==0){
            Node *jk=ans;
            while(jk->data == 0 && jk->next!=NULL){
                jk=jk->next;
            }
           
            return jk;
        }
        return ans;
        
       
    }
};
