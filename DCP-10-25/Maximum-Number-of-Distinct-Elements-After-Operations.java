import java.util.*;

class Solution {
    public int maxDistinctElements(int[] arr, int k) {
        Arrays.sort(arr);
        long next = Long.MIN_VALUE;
        int count = 0;
        for (int x : arr) {
            long left = (long) x - k;
            long right = (long) x + k;
            if (next < left) next = left;
            if (next <= right) {
                count++;
                next++;
            }
        }
        return count;
    }
}
