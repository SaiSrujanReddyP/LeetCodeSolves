class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long result = 0;
        unordered_map<int, long long> prefixMap;
        int count = 0;

        prefixMap[0] = 1;  

        for (int num : nums) {
            if (num % modulo == k) {
                count++;
            }

            int target = (count - k + modulo) % modulo;
            result += prefixMap[target];
            prefixMap[count % modulo]++;
        }

        return result;
    }
};
