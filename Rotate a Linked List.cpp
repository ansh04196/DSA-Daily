class Solution {
   private:
    pair<int, Node*> findLength(Node* head) {
        pair<int, Node*> res;
        
        Node* temp = head;
        Node* endNode = nullptr;
        int len = 0;
        
        while(temp) {
            // store the last node address
            if(temp->next == nullptr)
                endNode = temp;
            
            temp = temp->next;
            len++;
        }
        
        res.first = len;
        res.second = endNode;
        
        return res;
    }

  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        
        pair<int, Node*> p = findLength(head);
        int n = p.first;
        Node* enode = p.second;
        
        int req = k % n;
        if(req == 0)
            return head;
        
        Node* store_head = head;
        Node* temp = head;
        for(int i=0; i<req-1; i++) {
            temp = temp->next;
        }
        
        head = temp->next;
        temp->next = nullptr;
        enode->next = store_head;
        
        
        return head;
    }
};
