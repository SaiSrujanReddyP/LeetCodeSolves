class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long power(long long x, long long y) {
        long long res = 1;
        x %= MOD;
        while (y > 0) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }

    void initComb(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        initComb(n + 100);  
        vector<int> spf(maxValue + 1);
        for (int i = 2; i <= maxValue; ++i) {
            if (spf[i] == 0) {
                for (int j = i; j <= maxValue; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }

        long long result = 0;

        for (int val = 1; val <= maxValue; ++val) {
            int x = val;
            unordered_map<int, int> primeExponents;
            while (x > 1) {
                int p = spf[x];
                primeExponents[p]++;
                x /= p;
            }

            long long ways = 1;
            for (auto &[p, e] : primeExponents) {
                ways = ways * comb(n + e - 1, e) % MOD;
            }

            result = (result + ways) % MOD;
        }

        return result;
    }
};
