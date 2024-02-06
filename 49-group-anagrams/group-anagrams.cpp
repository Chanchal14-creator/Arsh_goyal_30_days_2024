class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(auto s: strs)
        {
            string s1=s;
            sort(s1.begin(),s1.end());
            m[s1].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto [x,y]:m)
        ans.push_back(y);
        return ans;
    }
};