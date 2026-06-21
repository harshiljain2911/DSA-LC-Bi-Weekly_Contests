class Solution {
public:
    long long countGood(const string& num, int k) {
        int n = num.size();
        // memo[pos][last+1][started] -- valid only when tight == false
        vector<array<array<long long,2>,11>> memo(n);
        for (auto &row : memo)
            for (auto &cell : row)
                cell = {-1, -1};

        function<long long(int,int,bool,bool)> dp =
            [&](int pos, int last, bool tight, bool started) -> long long {
            if (pos == n) return started ? 1 : 0;
            if (!tight && memo[pos][last+1][started] != -1)
                return memo[pos][last+1][started];

            int limit = tight ? (num[pos] - '0') : 9;
            long long res = 0;

            for (int d = 0; d <= limit; d++) {
                bool nTight = tight && (d == limit);
                if (!started && d == 0) {
                    res += dp(pos + 1, -1, nTight, false);
                } else if (!started || abs(d - last) <= k) {
                    res += dp(pos + 1, d, nTight, true);
                }
            }

            if (!tight) memo[pos][last+1][started] = res;
            return res;
        };

        return dp(0, -1, true, false);
    }

    long long upTo(long long x, int k) {
        if (x <= 0) return 0;
        return countGood(to_string(x), k);
    }

    long long goodIntegers(long long l, long long r, int k) {
        return upTo(r, k) - upTo(l - 1, k);
    }
};
