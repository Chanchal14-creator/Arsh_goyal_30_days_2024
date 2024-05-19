class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
        return -1;
        vector<int>row={1,-1,-1,-1,0,0,1,1};
        vector<int>col={1,-1,0,1,-1,1,-1,0};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visit(n,vector<bool>(n,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        int ans=0;
        while(!q.empty())
        {
           ans++;
           int len=q.size();
           for(int i=0;i<len;i++)
           {
           int r=q.front().first;
           int c=q.front().second;
           if(q.front().first==n-1&&q.front().second==n-1)
           return ans;
           for(int i=0;i<8;i++)
           {
            if(row[i]+r>=0&&row[i]+r<n&&col[i]+c>=0&&col[i]+c<m)
            {
                if(grid[row[i]+r][col[i]+c]==0&&!visit[row[i]+r][col[i]+c])
                {
                    q.push({row[i]+r,col[i]+c});
                    visit[row[i]+r][col[i]+c]=true;
                }
            }
           }
           q.pop(); 
           }
        }
        return -1;
    }
};