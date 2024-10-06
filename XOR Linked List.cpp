// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    // create a new node with the given data
    struct Node *new_node = new Node(data);

    // make the new node's npx point to the current head
    new_node->npx = head;

    // if the current head is not NULL, update the npx of the head
    if (head != NULL)
        head->npx = XOR(new_node, head->npx);

    // return the new node as the new head
    return new_node;
}

// function to print the linked list
vector<int> getList(struct Node *head) {
    // initialize three pointers: current, previous, and next
    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *next;

    // create a vector to store the values of the nodes in the list
    vector<int> vec;

    // iterate through the linked list
    while (curr != NULL) {
        // add the data of the current node to the vector
        vec.push_back(curr->data);

        // calculate the next node using XOR operation
        next = XOR(prev, curr->npx);

        // update the previous and current nodes
        prev = curr;
        curr = next;
    }

    // return the vector containing the values of the nodes in the list
    return vec;
}
