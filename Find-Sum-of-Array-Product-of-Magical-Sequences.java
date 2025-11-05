import java.util.*;

class Solution {
    static final long MOD = 1000000007;

    long powmod(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    public int magicalSum(int m, int k, int[] nums) {
        int n = nums.length;
        long[] fact = new long[m + 1], inv = new long[m + 1];
        fact[0] = inv[0] = 1;
        for (int i = 1; i <= m; i++) fact[i] = (fact[i - 1] * i) % MOD;
        inv[m] = powmod(fact[m], MOD - 2);
        for (int i = m; i > 0; i--) inv[i - 1] = (inv[i] * i) % MOD;

        long[][] pow = new long[n][m + 1];
        for (int i = 0; i < n; i++) {
            pow[i][0] = 1;
            for (int j = 1; j <= m; j++) pow[i][j] = (pow[i][j - 1] * nums[i]) % MOD;
        }

        long[][][][] dp = new long[n][m + 1][2 * m + 1][k + 1];
        for (int j = 0; j <= m; j++) dp[0][j][j][0] = (pow[0][j] * inv[j]) % MOD;

        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int p = 0; p <= 2 * m; p++) {
                    for (int q = 0; q <= k; q++) {
                        if (dp[i][j][p][q] == 0) continue;
                        for (int r = 0; r + j <= m; r++) {
                            int np = (p >> 1) + r;
                            int nq = q + (p & 1);
                            if (nq > k) continue;
                            dp[i + 1][j + r][np][nq] = 
                                (dp[i + 1][j + r][np][nq] + dp[i][j][p][q] * pow[i + 1][r] % MOD * inv[r]) % MOD;
                        }
                    }
                }
            }
        }

        long res = 0;
        for (int p = 0; p <= 2 * m; p++) {
            for (int q = 0; q <= k; q++) {
                if (Integer.bitCount(p) + q == k) {
                    res = (res + dp[n - 1][m][p][q] * fact[m]) % MOD;
                }
            }
        }
        return (int) res;
    }
}
