class Solution {
public:
    long long coloredCells(int n) {
        long long N = n;
        return N * N + (N - 1) * (N - 1);
    }
};
