class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days; 
        sort(meetings.begin(), meetings.end());
        
        int free_days = 0;
        int prev_end = 0; 
        for (auto& m : meetings) {
            int start = m[0], end = m[1];
            
            if (start > prev_end + 1) {
                free_days += (start - prev_end - 1);
            }
            prev_end = max(prev_end, end);
        }
        
        if (prev_end < days) {
            free_days += (days - prev_end);
        } 
        return free_days;
    }
};
