import java.util.*;

class Helper {
    private int x;
    private long sum;
    private TreeSet<Pair> top;
    private TreeSet<Pair> rest;
    private Map<Integer, Integer> occ;

    private static class Pair implements Comparable<Pair> {
        int freq, val;
        Pair(int f, int v) { freq = f; val = v; }
        public int compareTo(Pair o) {
            if (freq != o.freq) return Integer.compare(freq, o.freq);
            return Integer.compare(val, o.val);
        }
        public boolean equals(Object o) {
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return freq == p.freq && val == p.val;
        }
        public int hashCode() { return Objects.hash(freq, val); }
    }

    public Helper(int x) {
        this.x = x;
        this.sum = 0L;
        this.top = new TreeSet<>();
        this.rest = new TreeSet<>();
        this.occ = new HashMap<>();
    }

    public void insert(int num) {
        int old = occ.getOrDefault(num, 0);
        if (old > 0) removePair(new Pair(old, num));
        int now = old + 1;
        occ.put(num, now);
        addPair(new Pair(now, num));
    }

    public void remove(int num) {
        int cur = occ.getOrDefault(num, 0);
        if (cur == 0) return;
        removePair(new Pair(cur, num));
        int now = cur - 1;
        if (now == 0) occ.remove(num);
        else {
            occ.put(num, now);
            addPair(new Pair(now, num));
        }
    }

    public long get() { return sum; }

    private void addPair(Pair p) {
        if (top.size() < x) {
            top.add(p);
            sum += (long) p.freq * p.val;
            return;
        }
        if (!top.isEmpty()) {
            Pair boundary = top.first();
            if (p.compareTo(boundary) > 0) {
                top.add(p);
                sum += (long) p.freq * p.val;
                Pair moved = top.pollFirst();
                if (moved != null) {
                    sum -= (long) moved.freq * moved.val;
                    rest.add(moved);
                }
                return;
            }
        }
        rest.add(p);
    }

    private void removePair(Pair p) {
        if (top.remove(p)) {
            sum -= (long) p.freq * p.val;
            if (!rest.isEmpty()) {
                Pair toMove = rest.pollLast();
                top.add(toMove);
                sum += (long) toMove.freq * toMove.val;
            }
        } else {
            rest.remove(p);
        }
    }
}

class Solution {
    public long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        Helper h = new Helper(x);
        long[] ans = new long[n - k + 1];
        for (int i = 0; i < n; i++) {
            h.insert(nums[i]);
            if (i >= k) h.remove(nums[i - k]);
            if (i >= k - 1) ans[i - k + 1] = h.get();
        }
        return ans;
    }
}
