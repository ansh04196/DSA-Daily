/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node*temp=head;
        Node*newnode=new Node(data);
        if(!head){
            newnode->next=newnode;
            return newnode;
        }
        if(data<=head->data){
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
            return newnode;
        }
        if(head->next==head){
            head->next=newnode;
            newnode->next=head;
            return head;
        }
        while(temp->next!=head && temp->next->data<data){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return head;
    }
};
//GFG POTD solution for 26 May
