class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Early exit if out of bounds
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;

        int start = 0;
        int end = m * n - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return false;
    }
};

