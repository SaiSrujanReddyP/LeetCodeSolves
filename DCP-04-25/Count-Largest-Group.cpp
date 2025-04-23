class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> groupCount;

        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            groupCount[sum]++;
        }

        int maxSize = 0, count = 0;
        for (auto& pair : groupCount) {
            if (pair.second > maxSize) {
                maxSize = pair.second;
                count = 1;
            } else if (pair.second == maxSize) {
                count++;
            }
        }

        return count;
    }

private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
