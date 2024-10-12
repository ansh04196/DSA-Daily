//Back-end complete function Template for Java
class Solution {
    public int pairWithMaxSum(int arr[]) {
        if (arr.length < 2) return -1;

       
        int res = arr[0] + arr[1];
        for (int i = 1; i < arr.length - 1; i++)
            res = Math.max(res, arr[i] + arr[i + 1]);

        return res;
    }
}
