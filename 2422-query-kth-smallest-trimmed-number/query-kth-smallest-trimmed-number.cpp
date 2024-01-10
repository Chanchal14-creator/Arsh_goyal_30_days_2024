class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
       
        for(auto q:queries)
        {
            vector<int> v(nums.size());
            iota(v.begin(), v.end(), 0);
            int sum =0;
            int x=q[0];
            int y=q[1];
            int end= nums[0].size()-1;
            int start = nums[0].size()-y;
            
            for( int j=start;j<=end;j++)
            {
                 vector<vector<int>>v1(10);
                for(auto i:v)
                {
                    v1[nums[i][j]-'0'].push_back(i);
                }
                
                for(int i=0;i<v1.size();i++)
                {
                    sum+=v1[i].size();
                    if(sum>=x)
                    {
                        sum-=v1[i].size();
                        v=v1[i];
                        break;
                    }
                }
            }
            sort(v.begin(),v.end());
            
            ans.push_back(v[x-sum-1]);
            
            
        }
        return ans;
    }
};