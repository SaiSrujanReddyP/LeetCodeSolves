class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxTriplet = 0;
        int maxPrefix = nums[0];  
        int maxDiff = INT_MIN;     
        for (int j = 1; j < n - 1; j++) {
            maxDiff = max(maxDiff, maxPrefix - nums[j]);
            maxPrefix = max(maxPrefix, nums[j]); 
            maxTriplet = max(maxTriplet, (long long) maxDiff * nums[j + 1]);
        }

        return maxTriplet;
    }
};
