class Solution{
 
      static class Element {
        Node data;
        int level;
        int sum;
    }
 
    public static int sumOfLongRootToLeafPath(Node root)
    {
        /*
          maxSumLevel stores maximum sum so far in the path
          maxLevel stores maximum level so far
        */
        int maxSumLevel = root.data;
        int maxLevel = 0;
 
        /* queue to implement level order traversal */
        Queue<Element> que = new LinkedList<>();
        Element e = new Element();
 
        /* Each element variable stores the current Node,
         * it's level, sum in the path */
 
        e.data = root;
        e.level = 0;
        e.sum = root.data;
 
        /* push the root element*/
        que.add(e);
 
        /* do level order traversal on the tree*/
        while (!que.isEmpty()) {
            Element front = que.poll();
            Node curr = front.data;
 
            /* if the level of current front element is
             * greater than the maxLevel so far then update
             * maxSum*/
            if (front.level > maxLevel) {
                maxSumLevel = front.sum;
                maxLevel = front.level;
            }
 
            /* if another path competes then update if the
             * sum is greater than the previous path of same
             * height*/
            else if (front.level == maxLevel
                     && front.sum > maxSumLevel) {
                maxSumLevel = front.sum;
            }
 
            /* push the left element if exists*/
            if (curr.left != null) {
                e = new Element();
                e.data = curr.left;
                e.sum = e.data.data;
                e.sum += front.sum;
                e.level = front.level + 1;
                que.add(e);
            }
 
            /*push the right element if exists*/
            if (curr.right != null) {
                e = new Element();
                e.data = curr.right;
                e.sum = e.data.data;
                e.sum += front.sum;
                e.level = front.level + 1;
                que.add(e);
            }
        }
        /*return the answer*/
        return maxSumLevel;
    }
}
