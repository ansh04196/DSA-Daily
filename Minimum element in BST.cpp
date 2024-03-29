class Solution {
    // Function to find the minimum element in the given BST.
    int minValue(Node root) {
        // base case
        if (root == null) return -1;

        Node current = root;

        // leftmost node is minimum so we move in BST till left node is not
        // NULL.
        while (current.left != null) {
            current = current.left;
        }
        // returning the data at leftmost node.
        return (current.data);
    }
}
