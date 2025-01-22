class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        if (head == NULL)
            return head;

        Node *t = head;
        while (t != NULL) {
             Node *n = new Node(t->data);
            n->next = t->next;
            t->next = n;
            t = n->next;
        }

        t = head;
        Node *head2 = head->next;
        while (t != NULL) {
             if (t->random == NULL)
                t->next->random = NULL;
            else
                t->next->random = t->random->next;

            t = t->next->next;
        }

        t = head;
        Node *res = head->next;
        while (t != NULL) {
             Node *temp = t->next;
            t->next = temp->next;
            if (temp->next)
                temp->next = temp->next->next;
            t = t->next;
        }
        return head2;
    }
}; 
