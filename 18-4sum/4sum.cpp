class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long new_target = (long long)target - nums[i] - nums[j];  // Use long long
                int low = j + 1, high = n - 1;

                while (low < high) {
                    long long sum = (long long)nums[low] + nums[high];  // Use long long
                    if (sum < new_target)
                        low++;
                    else if (sum > new_target)
                        high--;
                    else {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while (low < high && nums[low] == res.back()[2]) low++;
                        while (low < high && nums[high] == res.back()[3]) high--;
                    }
                }
            }
        }

        return res;
    }
};
