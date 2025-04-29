
/*

  Node is defined as
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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // code here
        int count[3] = {0, 0 ,0};
        Node* temp = head;
        
        while(temp != NULL){
            count[temp->data]++;
            temp = temp->next;
        }
        
        temp = head;
        int i = 0;
        while(temp != NULL){
            if(count[i] == 0){
                i++;
            }else{
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }
        return head;
    }
};



//GFG POTD solution for 29 April
