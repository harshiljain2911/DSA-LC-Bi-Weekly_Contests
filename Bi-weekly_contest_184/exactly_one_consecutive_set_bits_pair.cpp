class Solution {
public:
    vector<int> toBinary(int x) {

        vector<int> ans;
        int r = 0;
        if (!x)
            return ans;

        while (x > 0) {
            r = x % 2;
            ans.push_back(r);
            x = x / 2;
        }
        ans.push_back(x);

        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool consecutiveSetBits(int n) {

        int count = 0;
        if (!n)
            return false;

        vector<int> ans = toBinary(n);

        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] == 1 && ans[i + 1] == 1)
               count++;
        }
        if(count == 1) return true;
        else return false;
    }
};
