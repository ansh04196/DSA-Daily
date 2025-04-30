
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow = head;
        Node* fast = head;
        int count = 0;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                slow = slow->next;
                fast = fast->next;
                if(slow==fast){
                    slow = head;
                    while(fast!=slow){
                        slow = slow->next;
                        fast = fast->next;
                    }
                    fast = fast->next;
                    count++;
                    while(fast!=slow){
                        count++;
                        fast = fast->next;
                    }
                    break;
                }
            }
        }
        return count;
    }
};


//GFG POTD solution for 30 April
