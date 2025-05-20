
/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    int max = -1;

    std::pair<int, bool> helper(Node* root, int target) {
        if (root == nullptr) {
            return {0, false};
        }
        
        std::pair<int, bool> left = helper(root->left, target);
        std::pair<int, bool> right = helper(root->right, target);
        
        if (root->data == target) {
            this->max = std::max(left.first, right.first);
            return {0, true};
        }

        if (left.second or right.second) {
            this->max = std::max(left.first + right.first + 1, this->max);
            return {(left.second ? left.first : right.first) + 1, true};
        }
        return {std::max(left.first, right.first) + 1, false};
    }

  public:
    int minTime(Node* root, int target) {
        helper(root, target);
        return this->max;
    }
};


//GFG POTD solution for 20 May
