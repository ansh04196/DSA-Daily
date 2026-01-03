/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;
    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
public:
    Node* merge(Node* h1, Node* h2) {
        if (!h1) return h2;
        if (!h2) return h1;
        
        Node* result;
        if (h1->data < h2->data) {
            result = h1;
            result->bottom = merge(h1->bottom, h2);
        } else {
            result = h2;
            result->bottom = merge(h1, h2->bottom);
        }
        result->next = NULL;
        return result;
    }
    
    Node* flatten(Node* root) {
        if (!root || !root->next) return root;
        
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
};
