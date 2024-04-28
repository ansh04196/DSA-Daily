class Solution {
    public:
    Node * deleteK(Node *head,int K){
       if(head==NULL) // check if the list is empty
        return NULL;
       
       Node *temp = head; // create a temporary node to traverse the list
       Node *back; // create a pointer to keep track of the previous node
       int kount = 1; // initialize a counter for counting nodes
       
       if(K==1) // if the given value of K is 1, it will always result in an empty list
        return NULL;
       
       while(temp!=NULL and temp->next) // traverse the list until the end or last node
       {
           kount++; // increment the counter
           back = temp; // update the previous node
           temp = temp->next; // move to the next node
           
           if(kount==K) // if the counter equals the given value of K
           {
               Node *r = temp->next; // create a pointer to the next node
               free(temp); // delete the current node
               back->next = r; // update the link between the previous and next node
               temp = r; // update the current node
               kount=1; // reset the counter
           }
           
       }
       return head; // return the modified list
    }
};
