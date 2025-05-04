class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count[100] = {0};
        int res = 0;
        
        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            int key = a < b ? a * 10 + b : b * 10 + a;
            res += count[key];
            count[key]++;
        }
        
        return res;
    }
};
