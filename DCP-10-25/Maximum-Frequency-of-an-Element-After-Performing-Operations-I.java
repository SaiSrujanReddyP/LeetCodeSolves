import java.util.*;

class Solution {
    public int maxFrequency(int[] nums, int k, int numOps) {
        int maxV = 0;
        for (int v : nums) if (v > maxV) maxV = v;
        int limit = maxV + k;
        int[] cnt = new int[limit + 1];
        for (int v : nums) cnt[v]++;
        int[] pref = new int[limit + 1];
        pref[0] = cnt[0];
        for (int i = 1; i <= limit; i++) pref[i] = pref[i - 1] + cnt[i];
        int res = 0;
        for (int t = 0; t <= limit; t++) {
            int lo = t - k;
            if (lo < 0) lo = 0;
            int hi = t + k;
            if (hi > limit) hi = limit;
            int total = pref[hi] - (lo > 0 ? pref[lo - 1] : 0);
            int equal = (t <= maxV ? cnt[t] : 0);
            int reachableNotEqual = total - equal;
            int cur = equal + Math.min(numOps, reachableNotEqual);
            if (cur > res) res = cur;
        }
        return res;
    }
}
