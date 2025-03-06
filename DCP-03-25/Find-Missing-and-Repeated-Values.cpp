#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        unordered_set<int> seen;
        int repeated, missing;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                if (!seen.insert(val).second) { 
                    repeated = val;
                }
            }
        }
        for (int i = 1; i <= total; ++i) {
            if (!seen.count(i)) {
                missing = i;
                break;
            }
        }

        return {repeated, missing};
    }
};
