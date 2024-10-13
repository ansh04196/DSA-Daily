class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        if (head == NULL) {
        return 0;
    }

    // Count this node plus the rest of the list
    return 1 + getCount(head->next);
    }
};
