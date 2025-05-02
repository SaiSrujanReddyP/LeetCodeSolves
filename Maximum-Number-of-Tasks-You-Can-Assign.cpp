class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        deque<int> dq(tasks.begin(), tasks.begin() + k);
        multiset<int> ws(workers.end() - k, workers.end());

        for (int i = k - 1; i >= 0; --i) {
            int hardest = dq.back(); dq.pop_back();
            auto it = ws.lower_bound(hardest);
            if (it != ws.end()) {
                ws.erase(it);
                continue;
            }
            it = ws.lower_bound(hardest - strength);
            if (it == ws.end() || pills == 0) return false;

            ws.erase(it);
            pills--;
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int lo = 0, hi = min(tasks.size(), workers.size()), res = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return res;
    }
};
