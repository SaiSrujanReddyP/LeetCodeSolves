class Solution {
    public int divide(int a, int b) {
        if (a == Integer.MIN_VALUE && b == -1) return Integer.MAX_VALUE;
        long x = Math.abs((long) a);
        long y = Math.abs((long) b);
        int res = 0;
        while (x >= y) {
            long t = y, m = 1;
            while (x >= (t << 1)) {
                t <<= 1;
                m <<= 1;
            }
            x -= t;
            res += m;
        }
        return (a > 0) == (b > 0) ? res : -res;
    }
}
