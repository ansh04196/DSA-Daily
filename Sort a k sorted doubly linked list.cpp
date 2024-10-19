class DLLNodeComparator {
public:
    bool operator() (const DLLNode *node1, const DLLNode *node2) {
        return node1->data > node2->data;
    }
};

class Solution
{
public:
    
    DLLNode *sortAKSortedDLL(DLLNode *head, int k)
    {
        // code here
        if(!head)
        return NULL;
        
        priority_queue <DLLNode*, vector<DLLNode*>, DLLNodeComparator> pq;        DLLNode *newHead = NULL;
        
        DLLNode *p = head;
        
        for(int i = 0; p != NULL and i<=k; i++) {
            pq.push(p);
            p = p->next;
        }
        DLLNode *curr;
        while(!pq.empty()) {
            if(newHead == NULL) {
                newHead = pq. top();
                newHead->prev = NULL;
                curr = newHead;
            }
            else {
                curr->next = pq. top();
                pq. top()->prev = curr;
                curr = pq. top();

            }
            
            pq.pop();
            
            if(p) {
                pq.push(p);
                p = p->next;
            }
        }
        curr->next = NULL;
        return newHead;
    }
};
