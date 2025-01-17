class Solution {
  public:
    // Function to reverse a linked list.
    Node *reverseList(Node *head) {
        if (head == NULL)
            return NULL;

        // taking three pointers to store the current, previous and next nodes.
        Node *prev = NULL;
        Node *current = head;
        Node *next = current->next;

        while (current != NULL) {
            // taking the next node as next.
            next = current->next;

            // storing the previous node in link part of current node.
            current->next = prev;

            // updating prev from previous node to current node.
            prev = current;

            // updating current node to next node.
            current = next;
        }

        return prev;
    }
};
