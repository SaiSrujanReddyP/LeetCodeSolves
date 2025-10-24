class Solution {
    public int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++) {
            if (balanced(i)) return i;
        }
        return -1;
    }

    private boolean balanced(int x) {
        int[] freq = new int[10];
        while (x > 0) {
            freq[x % 10]++;
            x /= 10;
        }
        for (int d = 0; d < 10; d++) {
            if (freq[d] > 0 && freq[d] != d) return false;
        }
        return true;
    }
}
