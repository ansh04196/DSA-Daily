/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution
{
public:
  vector<vector<int>> levelOrder(Node *root)
  {
    if (root == nullptr)
      return {};
    vector<vector<int>> result;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
      int level = q.size();
      vector<int> levelNode;
      for (int i = 0; i < level; i++)
      {
        Node *temp = q.front();
        q.pop();
        levelNode.push_back(temp->data);
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
      result.push_back(levelNode);
    }
    return result;
  }
};



//GFG POTD solution for 02 February
