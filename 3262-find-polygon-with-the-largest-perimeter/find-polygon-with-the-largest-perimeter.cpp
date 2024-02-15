class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long  sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
        cout<<sum;
        for (int i=nums.size()-1;i>=0;i--)
        {
            sum-=nums[i];
            if(i==2)
            {
                if(sum<nums[i])
                return -1;
            }
            else if(i<2)
            return -1;

            if(sum>nums[i]){
            return sum+nums[i];
            }
        }
        return 0;
    }
};