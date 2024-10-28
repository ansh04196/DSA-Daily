// Solution class with quickSort function
class Solution {
  public:

    struct Node* getTail(struct Node* cur) {
        while (cur != NULL && cur->next != NULL)
            cur = cur->next;
        return cur;
    }

    // Here the sorting happens exclusive of the end node
    struct Node* quickSortRecur(struct Node* head, struct Node* end) {
        // Base condition
        if (!head || head == end)
            return head;

        Node *newHead = NULL, *newEnd = NULL;

        // Partition the list, newHead and newEnd will be updated by the partition
        // function
        struct Node* pivot = partition(head, end, newHead, newEnd);

        // If pivot is the smallest element - no need to recur for the left part.
        if (newHead != pivot) {
            // Set the node before the pivot node as NULL
            struct Node* tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = NULL;

            // Recur for the list before pivot
            newHead = quickSortRecur(newHead, tmp);

            // Change next of last node of the left half to pivot
            tmp = getTail(newHead);
            tmp->next = pivot;
        }

        // Recur for the list after the pivot element
        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }

    struct Node* quickSort(struct Node* head) {
        return quickSortRecur(head, getTail(head));
    }
};
