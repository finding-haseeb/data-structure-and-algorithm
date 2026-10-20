class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, 1e9);
        vector<int> prefDrop(n, 0);

        // prefix maximum
        for(int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // suffix minimum
        for(int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        // count normal descents
        for(int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1];

            if(nums[i - 1] > nums[i]) {
                prefDrop[i]++;
            }
        }

        auto check = [&](int k) {
            for(int start = 0; start < n; start += k) {
                int end = start + k - 1;

                // normal descents inside block
                int drops = prefDrop[end] - prefDrop[start];

                // circular descent: last -> first
                if(nums[end] > nums[start]) {
                    drops++;
                }

                // block cannot be rotated into sorted order
                if(drops > 1) {
                    return false;
                }

                // previous elements must be <= this block
                if(prefMax[start] > suffMin[start]) {
                    return false;
                }
            }

            return true;
        };

        int ans = 0;

        // find all divisors of n
        for(int i = 1; i <= n / i; i++) {
            if(n % i == 0) {

                if(check(i)) {
                    ans += i;
                }

                if(i != n / i && check(n / i)) {
                    ans += n / i;
                }
            }
        }

        return ans;
    }
};