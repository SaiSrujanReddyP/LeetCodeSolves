class Solution {
    public int numberOfBeams(String[] bank) {
        int last = 0;
        int beams = 0;
        for (String row : bank) {
            int curr = 0;
            for (char ch : row.toCharArray()) {
                if (ch == '1') curr++;
            }
            if (curr > 0) {
                beams += last * curr;
                last = curr;
            }
        }
        return beams;
    }
}
