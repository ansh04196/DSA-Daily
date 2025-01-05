class Solution {
    public List<Integer> sumClosest(int[] arr, int target) {
        // code here 
        Arrays.sort(arr);
        int closestSum = Integer.MAX_VALUE;
        int left = 0, right = arr.length - 1;
         boolean found = false;
         

        // Variables to store the result
        int closestLeft = 0, closestRight = 0;

        while (left < right) {
            int sum = arr[left] + arr[right];

            // Update the closest sum and pair if needed
            if (Math.abs(target - sum) < Math.abs(target - closestSum)) {
                closestSum = sum;
                closestLeft = arr[left];
                closestRight = arr[right];
                 found = true;
            }

            // Adjust pointers
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                // If the exact target is found, return immediately
                return Arrays.asList(arr[left], arr[right]);
            }
        }
         // If no pair was found, return an empty list
        if (!found) {
            return new ArrayList<>();
        }

        // Return the closest pair
        return Arrays.asList(closestLeft, closestRight);
    }
}
