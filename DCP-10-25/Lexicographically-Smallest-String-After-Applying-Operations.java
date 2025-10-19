import java.util.*;

class Solution {
    public String findLexSmallestString(String s, int a, int b) {
        Set<String> seen = new HashSet<>();
        Queue<String> q = new LinkedList<>();
        String res = s;
        q.offer(s);
        seen.add(s);

        while (!q.isEmpty()) {
            String cur = q.poll();
            if (cur.compareTo(res) < 0) res = cur;

            char[] ch = cur.toCharArray();
            for (int i = 1; i < ch.length; i += 2)
                ch[i] = (char) ((ch[i] - '0' + a) % 10 + '0');
            String added = new String(ch);

            if (seen.add(added)) q.offer(added);

            String rotated = cur.substring(cur.length() - b) + cur.substring(0, cur.length() - b);
            if (seen.add(rotated)) q.offer(rotated);
        }
        return res;
    }
}
