class Solution {
    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (code(nums.clone(), i, -1)) ans++;
                if (code(nums.clone(), i, 1)) ans++;
            }
        }
        return ans;
    }

    private boolean code(int[] arr, int pos, int dir) {
        int n = arr.length;
        while (pos >= 0 && pos < n) {
            if (arr[pos] == 0) {
                pos += dir;
            } else {
                arr[pos]--;
                dir = -dir;
                pos += dir;
            }
        }
        for (int val : arr)
            if (val != 0)
                return false;
        return true;
    }
}
