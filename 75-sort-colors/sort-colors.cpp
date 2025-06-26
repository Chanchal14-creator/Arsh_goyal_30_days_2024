class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x=0;
        int y=0;
        int z=0;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            x++;
            else if(nums[i]==1)
            y++;
            else if(nums[i]==2)
            z++;
        }
        for (int i=0;i<nums.size();i++)
        {
            if(i<x)
            nums[i] = 0;
            else if(i<x+y)
            nums[i] = 1;
            else if(i<z+x+y)
            nums[i] = 2;
        }
        
    }
};