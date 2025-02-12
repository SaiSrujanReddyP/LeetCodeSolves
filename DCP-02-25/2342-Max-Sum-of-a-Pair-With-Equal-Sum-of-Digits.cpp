#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap;
        int maxSum = -1;

        for (int num : nums) {
            int sumDigits = 0, temp = num;
            while (temp > 0) {
                sumDigits += temp % 10;
                temp /= 10;
            }

            if (digitSumMap.find(sumDigits) != digitSumMap.end()) {
                maxSum = max(maxSum, digitSumMap[sumDigits] + num);
                digitSumMap[sumDigits] = max(digitSumMap[sumDigits], num);
            } else {
                digitSumMap[sumDigits] = num;
            }
        }

        return maxSum;
    }
};
