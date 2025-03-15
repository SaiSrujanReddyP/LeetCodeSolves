#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int minVal = nums[0]; 
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < minVal) {
                minVal = nums[i]; 
            }
        }
        return minVal;
    }

    int findMax(vector<int>& nums) {
        int maxVal = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i]; 
            }
        }
        return maxVal;
    }

    bool canRobWithCapability(vector<int>& nums, int k, int capability) {
        int count = 0;  
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] <= capability) {
                count++; 
                i++;     
            }
        }

        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int minElement = findMin(nums);
        int maxElement = findMax(nums);

        cout << "Min element: " << minElement << endl;
        cout << "Max element: " << maxElement << endl;

        int left = minElement;
        int right = maxElement;
        int ans = right;  

        while (left <= right) {
            int mid = left + (right - left) / 2; 

            if (canRobWithCapability(nums, k, mid)) {
                ans = mid; 
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }

        return ans;
    }
};