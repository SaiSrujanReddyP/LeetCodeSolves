import java.util.*;

class Solution {
    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        int[] res = new int[n - k + 1];
        for (int i = 0; i <= n - k; i++) {
            Map<Integer, Integer> f = new HashMap<>();
            for (int j = i; j < i + k; j++) f.put(nums[j], f.getOrDefault(nums[j], 0) + 1);
            List<int[]> a = new ArrayList<>();
            for (var e : f.entrySet()) a.add(new int[]{e.getKey(), e.getValue()});
            a.sort((p, q) -> q[1] != p[1] ? q[1] - p[1] : q[0] - p[0]);
            Set<Integer> s = new HashSet<>();
            for (int j = 0; j < Math.min(x, a.size()); j++) s.add(a.get(j)[0]);
            int sum = 0;
            for (int j = i; j < i + k; j++) if (s.contains(nums[j])) sum += nums[j];
            res[i] = sum;
        }
        return res;
    }
}
