class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; 
        long long oddCount = n / 2;        

        long long evenChoices = modPow(5, evenCount, MOD);
        long long oddChoices = modPow(4, oddCount, MOD);

        return (evenChoices * oddChoices) % MOD;
    }
};
