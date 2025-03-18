class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, maxLen = 0, usedBits = 0;

        for (int right = 0; right < n; right++) {
            while ((usedBits & nums[right]) != 0) {
                usedBits ^= nums[left]; 
                left++; 
            }
            
            usedBits |= nums[right]; 
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
