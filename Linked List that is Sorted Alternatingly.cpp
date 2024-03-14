class Solution
{
    public:    
    void reverselist(Node *&head)
    {
    	Node* prev = NULL, *curr = head, *next;
    	
    	while (curr)
    	{
    		next = curr->next;   // storing value for next node
    		curr->next = prev;   // linking node to previous node
    		prev = curr;         // updating value of prev node
    		curr = next;         // updating value of current node
    	}
    	head = prev;
    }
    
    Node *mergelist(Node *head1, Node *head2)
    {
    	if (!head1) return head2;  // base cases
    	if (!head2) return head1;  // base cases
    	
    	Node *temp = NULL;
    	
    	if (head1->data < head2->data)
    	{
    		temp = head1;     // picking the lower value
    		head1->next = mergelist(head1->next, head2);
    		// recursively merging the remaining list
    	}
    	else
    	{
    		temp = head2;     // picking the lower value
    		head2->next = mergelist(head1, head2->next);
    		// recursively merging the remaining list
    	}
    	return temp;
    }
    
    void splitList(Node *head, Node **Ahead, Node **Dhead)
    {
    	*Ahead = new Node(0);
    	    // first node for the list (will be discarded later)
    	*Dhead = new Node(0);
    	    // first node for the list (will be discarded later)
    	
    	Node *ascn = *Ahead;
    	Node *dscn = *Dhead;
    	Node *curr = head;
    	
    	while (curr)
    	{
    	    // first element goes to ascending list
    		ascn->next = curr;
    		ascn = ascn->next;
    		curr = curr->next;
    		
    		if (curr)
    		{
    		    // second element goes to descending list
    			dscn->next = curr;
    			dscn = dscn->next;
    			curr = curr->next;
    		}
    	}
    	ascn->next = NULL;
    	dscn->next = NULL;
    	*Ahead = (*Ahead)->next;   // discarding first element
    	*Dhead = (*Dhead)->next;   // discarding first element
    }
    
    void sort(Node **head)
    {
    	Node *Ahead, *Dhead;
    	splitList(*head, &Ahead, &Dhead);
    	// function to split the list
    	// Ahead stores the elements with even index (0,2,4...)
    	// Dhead stores elements with odd index
    	
    	reverselist(Dhead);
    	// reversing list with head Dhead since it contains
    	// elements in decreasing order
    	
    	*head = mergelist(Ahead, Dhead);
    	// merging back both lists in increasing order
    }
};
    
