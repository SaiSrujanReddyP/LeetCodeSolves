class Solution {
public:
    int maximumCount(std::vector<int>& nums) {
        int neg = 0, pos = 0;
        for (int num : nums) {
            if (num > 0) pos++;
            else if (num < 0) neg++;
        }
        return std::max(neg, pos);
    }
};
