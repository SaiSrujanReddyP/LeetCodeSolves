class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string lowerBound = to_string(start);
        string upperBound = to_string(finish);
        int totalLength = upperBound.length();

        while (lowerBound.length() < totalLength) {
            lowerBound = '0' + lowerBound;
        }

        int prefixLength = totalLength - s.length();
        vector<long long> cache(totalLength, -1);

        function<long long(int, bool, bool)> helper = [&](int pos, bool tightLow, bool tightHigh) -> long long {
            if (pos == totalLength) return 1;

            if (!tightLow && !tightHigh && cache[pos] != -1) return cache[pos];

            int minDigit = tightLow ? lowerBound[pos] - '0' : 0;
            int maxDigit = tightHigh ? upperBound[pos] - '0' : 9;

            long long ways = 0;

            if (pos < prefixLength) {
                for (int d = minDigit; d <= min(maxDigit, limit); ++d) {
                    bool newTightLow = tightLow && (d == minDigit);
                    bool newTightHigh = tightHigh && (d == maxDigit);
                    ways += helper(pos + 1, newTightLow, newTightHigh);
                }
            } else {
                int targetDigit = s[pos - prefixLength] - '0';
                if (targetDigit >= minDigit && targetDigit <= min(maxDigit, limit)) {
                    ways += helper(pos + 1, tightLow && (targetDigit == minDigit),
                                              tightHigh && (targetDigit == maxDigit));
                }
            }

            if (!tightLow && !tightHigh) cache[pos] = ways;
            return ways;
        };

        return helper(0, true, true);
    }
};
