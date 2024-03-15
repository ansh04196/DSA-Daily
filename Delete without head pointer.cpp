/* Link list node 
struct Node
{
    int data;
    Node* next;
}*/

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
        //storing the node next to given node in a pointer.	
    	Node* temp = del_node->next;
    	
    	//copying the data of pointer in the given current node.
    	del_node->data = temp->data;
    	
    	//storing the next node to pointer in link part of current node.
    	del_node->next = temp->next;

    	// freeing memory.
    	free(temp);
    	
    }
};
