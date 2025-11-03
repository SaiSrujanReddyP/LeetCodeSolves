class Solution {
    public int minCost(String colors, int[] time) {
        int n = colors.length();
        int ans = 0;
        int prev = 0;
        for (int i = 1; i < n; i++) {
            if (colors.charAt(i) == colors.charAt(prev)) {
                ans += Math.min(time[i], time[prev]);
                if (time[i] > time[prev]) prev = i;
            } else {
                prev = i;
            }
        }
        return ans;
    }
}
