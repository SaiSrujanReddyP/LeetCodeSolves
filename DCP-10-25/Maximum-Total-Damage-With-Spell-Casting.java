import java.util.*;

class Solution {
    public long maximumTotalDamage(int[] power) {
        Map<Integer, Long> damageMap = new HashMap<>();
        for (int p : power) {
            damageMap.put(p, damageMap.getOrDefault(p, 0L) + p);
        }
        List<Integer> keys = new ArrayList<>(damageMap.keySet());
        Collections.sort(keys);
        int n = keys.size();
        long[] dp = new long[n];
        dp[0] = damageMap.get(keys.get(0));
        
        for (int i = 1; i < n; i++) {
            long curr = damageMap.get(keys.get(i));
            int j = i - 1;            
            while (j >= 0 && keys.get(j) >= keys.get(i) - 2) {
                j--;
            }
            
            long include = curr + (j >= 0 ? dp[j] : 0);
            long exclude = dp[i - 1];
            dp[i] = Math.max(include, exclude);
        }
        return dp[n - 1];
    }
}
