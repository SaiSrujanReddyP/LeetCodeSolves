import java.util.*;

class Solution {
    int n, k;
    String s;
    Map<String, Integer> memo;

    public int maxPartitionsAfterOperations(String s, int k) {
        this.s = s;
        this.k = k;
        this.n = s.length();
        this.memo = new HashMap<>();
        return dfs(0, 0, 0);
    }

    private int dfs(int i, int usedChange, int mask) {
        if (i == n) return 1;
        String key = i + "," + usedChange + "," + mask;
        if (memo.containsKey(key)) return memo.get(key);

        int ans = 1; 

        int curMask = mask | (1 << (s.charAt(i) - 'a'));
        if (Integer.bitCount(curMask) <= k)
            ans = Math.max(ans, dfs(i + 1, usedChange, curMask));

        if (Integer.bitCount(curMask) > k)
            ans = Math.max(ans, 1 + dfs(i + 1, usedChange, 1 << (s.charAt(i) - 'a')));

        if (usedChange == 0) {
            for (int c = 0; c < 26; c++) {
                int newMask = mask | (1 << c);
                if (Integer.bitCount(newMask) <= k)
                    ans = Math.max(ans, dfs(i + 1, 1, newMask));
                else
                    ans = Math.max(ans, 1 + dfs(i + 1, 1, 1 << c));
            }
        }

        memo.put(key, ans);
        return ans;
    }
}
