class Solution {
public:

    vector<int> digits(long long n) {
        vector<int> ans;

        if(n == 0) {
            ans.push_back(0);
            return ans;
        }

        while(n > 0) {
            ans.push_back(n % 10);
            n /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    long long goodIntegers(long long l, long long r, int k) {

        long long count = 0;

        for(long long i = l; i <= r; i++) {

            vector<int> d = digits(i);

            bool ok = true;

            for(int j = 0; j < d.size() - 1; j++) {

                if(abs(d[j] - d[j + 1]) > k) {
                    ok = false;
                    break;
                }
            }

            if(ok) count++;
        }

        return count;
    }
};
