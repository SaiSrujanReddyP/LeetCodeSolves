#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (i + 2 >= n) return -1; 
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                operations++;
            }
        }
        
        return operations;
    }
};