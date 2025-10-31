import java.util.*;

class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        HashSet<Integer> seen = new HashSet<>();
        int[] res = new int[2];
        int i = 0;
        
        for (int num : nums) {
            if (seen.contains(num)) {
                res[i++] = num;
                if (i == 2) break;
            } else {
                seen.add(num);
            }
        }
        return res;
    }
}
