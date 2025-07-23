class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return divide(nums, 0, nums.size() - 1);
    }

    int divide(vector<int>& a, int left, int right) {
        if (left >= right)
            return 0;

        int mid = (left + right) / 2;
        int count = 0;

        count += divide(a, left, mid);
        count += divide(a, mid + 1, right);
        count += merge(a, left, mid, right);

        return count;
    }

    int merge(vector<int>& a, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;

        // Count reverse pairs
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)a[i] > 2LL * a[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (a[i] <= a[j]) {
                temp.push_back(a[i++]);
            } else {
                temp.push_back(a[j++]);
            }
        }

        while (i <= mid) temp.push_back(a[i++]);
        while (j <= right) temp.push_back(a[j++]);

        for (int k = left; k <= right; k++) {
            a[k] = temp[k - left];
        }

        return count;
    }
};
