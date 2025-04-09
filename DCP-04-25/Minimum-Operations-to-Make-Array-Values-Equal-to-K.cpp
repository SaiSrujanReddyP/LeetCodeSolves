class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num : nums) {
            if (num < k) return -1;
        }
        
        unordered_set<int> greater;
        for (int num : nums) {
            if (num > k) {
                greater.insert(num);
            }
        }
        
        return greater.size();  
    }
};
