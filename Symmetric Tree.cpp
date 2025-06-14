/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
public:
bool sym(Node* a,Node* b)
{
    if (!a && !b) return true;
    if (!a || !b) return false;
    if (a->data != b->data) return false;
    return (sym(a->left,b->right) && sym(a->right,b->left));
}
bool isSymmetric(Node* root) 
{
    if (!root) return true;
    return sym(root->left,root->right);
}
};
//GFG POTD solution for 14 June
