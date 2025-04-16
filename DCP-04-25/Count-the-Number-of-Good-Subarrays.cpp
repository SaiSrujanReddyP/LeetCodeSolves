#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long result = 0;
        long long pairs = 0;
        unordered_map<int, int> freq;
        int left = 0;
        auto count_pairs = [&](int x) {
            return (x * (x - 1)) / 2;
        };

        for (int right = 0; right < nums.size(); ++right) {
            int num = nums[right];
            int count_num = ++freq[num];
            pairs += count_num - 1;
            while (pairs >= k) {
                result += nums.size() - right;
                int left_num = nums[left];
                int left_count = --freq[left_num];
                pairs -= left_count;
                left++;
            }
        }
        return result;
    }
};
