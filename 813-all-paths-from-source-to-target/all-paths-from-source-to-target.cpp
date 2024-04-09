class Solution {
public:
vector<vector<int>>ans;
    void dfs (vector<vector<int>>graph,int node,vector<int>v)
    {
        v.push_back(node);
        if(graph[node].size()==0||node==graph.size()-1)
        {
            if(node==graph.size()-1)
            ans.push_back(v);
            return;
        }
        for(auto i:graph[node])
        {
            dfs(graph,i,v);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph,0,{});
        return ans;
    }
};