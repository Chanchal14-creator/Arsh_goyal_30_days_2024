class Solution {
public:
vector<vector<int>>ans;
void recursion(vector<int>added,vector<int>to_be)
{
    if(to_be.size()==0){
    ans.push_back(added);
    return ;
    }

    int front = to_be[to_be.size()-1];
    to_be.pop_back();
    recursion(added,to_be);
    added.push_back(front);
    recursion(added,to_be);    
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>added;
        int front = nums[nums.size()-1];
        nums.pop_back();
        recursion(added,nums);
        added.push_back(front);
        recursion(added,nums);
        return ans;
    }
};