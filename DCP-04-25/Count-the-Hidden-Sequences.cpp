class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min_val = 0, max_val = 0, current_val = 0;
        for (int diff : differences) {
            current_val += diff;
            min_val = min(min_val, current_val);
            max_val = max(max_val, current_val);
        }
        long long valid_min = lower - min_val;
        long long valid_max = upper - max_val;
        if (valid_max >= valid_min) {
            return valid_max - valid_min + 1;
        }
        return 0;
    }
};
