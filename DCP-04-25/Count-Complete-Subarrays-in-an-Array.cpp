#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> totalDistinct(nums.begin(), nums.end());
        int totalDistinctCount = totalDistinct.size();
        
        int left = 0, result = 0;
        unordered_map<int, int> windowMap;
        int distinctInWindow = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            if (windowMap[nums[right]] == 0) {
                distinctInWindow++;
            }
            windowMap[nums[right]]++;
            
            while (distinctInWindow == totalDistinctCount) {
                result += nums.size() - right;
                
                windowMap[nums[left]]--;
                if (windowMap[nums[left]] == 0) {
                    distinctInWindow--;
                }
                left++;
            }
        }
        
        return result;
    }
};
