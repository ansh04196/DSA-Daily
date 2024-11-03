class Solution {
  public:
    bool isLengthEven(Node** head) {
        Node* fast =* head;
        
         while (fast && fast->next) {
            fast = fast->next->next;
        }
        
        // If fast ends up at NULL, the length is even; otherwise, it's odd
        return fast == NULL;
    }
};
