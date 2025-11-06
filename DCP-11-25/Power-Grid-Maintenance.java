import java.util.*;

class Solution {
    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= c; i++) adj.add(new ArrayList<>());
        for (int[] e : connections) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        int[] comp = new int[c + 1];
        int compId = 0;
        for (int i = 1; i <= c; i++) {
            if (comp[i] == 0) {
                compId++;
                Deque<Integer> q = new ArrayDeque<>();
                q.add(i);
                comp[i] = compId;
                while (!q.isEmpty()) {
                    int cur = q.poll();
                    for (int nei : adj.get(cur)) {
                        if (comp[nei] == 0) {
                            comp[nei] = compId;
                            q.add(nei);
                        }
                    }
                }
            }
        }
        TreeSet<Integer>[] active = new TreeSet[compId + 1];
        for (int i = 1; i <= compId; i++) active[i] = new TreeSet<>();
        for (int i = 1; i <= c; i++) active[comp[i]].add(i);
        List<Integer> res = new ArrayList<>();
        for (int[] q : queries) {
            int type = q[0], x = q[1];
            if (type == 1) {
                if (active[comp[x]].contains(x)) res.add(x);
                else res.add(active[comp[x]].isEmpty() ? -1 : active[comp[x]].first());
            } else {
                active[comp[x]].remove(x);
            }
        }
        int[] ans = new int[res.size()];
        for (int i = 0; i < res.size(); i++) ans[i] = res.get(i);
        return ans;
    }
}
