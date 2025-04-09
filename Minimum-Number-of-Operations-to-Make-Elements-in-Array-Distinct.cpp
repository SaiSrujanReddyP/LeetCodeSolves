class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        
        while (true) {
            unordered_set<int> s(nums.begin(), nums.end());
            if (s.size() == nums.size()) return operations;
            if (nums.size() <= 3) return operations + 1;            
            nums.erase(nums.begin(), nums.begin() + 3);
            operations++;
        }
    }
};
