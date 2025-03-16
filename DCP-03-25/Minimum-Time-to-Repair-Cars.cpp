#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Repair(vector<int>& ranks, int cars, long long mid) {
        long long totalCars = 0;
        for (int r : ranks) {
            totalCars += sqrt(mid / r);
            if (totalCars >= cars) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1LL * (*min_element(ranks.begin(), ranks.end())) * cars * cars;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (Repair(ranks, cars, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;  
    }
};
