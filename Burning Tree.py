from collections import deque, defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def minTimeToBurnTree(root, target):
    if not root:
        return 0

    # Step 1: Build the graph (adjacency list)
    graph = defaultdict(list)
    def buildGraph(node, parent=None):
        if node:
            if parent:
                graph[node.val].append(parent.val)
                graph[parent.val].append(node.val)
            if node.left:
                buildGraph(node.left, node)
            if node.right:
                buildGraph(node.right, node)
    
    buildGraph(root)

    # Step 2: BFS from the target node
    queue = deque([target])
    visited = set([target])
    time = 0

    while queue:
        for _ in range(len(queue)):
            node = queue.popleft()
            for neighbor in graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        if queue:
            time += 1

    return time

# Example usage:
# Constructing the tree from the example
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.right = TreeNode(6)
root.left.right.left = TreeNode(7)
root.left.right.right = TreeNode(8)
root.right.right.right = TreeNode(9)
root.right.right.right.right = TreeNode(10)

target = 8
print(minTimeToBurnTree(root, target))  # Output: 7
