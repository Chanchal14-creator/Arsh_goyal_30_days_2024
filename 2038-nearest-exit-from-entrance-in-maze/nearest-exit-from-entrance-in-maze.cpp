class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int m=maze.size();
        int n=maze[0].size();
        // queue of pair of pair {steps,{row,col}}
        queue<pair<int,pair<int,int>>> q;
        //starting from intital row and column
        //instead of using visited matrix we can change maze from '.' -> '+' ...to mark visitec

        q.push({0,{e[0],e[1]}});
        // travelling in all 4 directions
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        maze[e[0]][e[1]]='+';
        while(!q.empty()){
            auto it=q.front();
            q.pop();
           
            int steps=it.first;
            int row=it.second.first;
            int col=it.second.second;
            //checking if the row,col is border or not.. 
            //steps!=0 check if it was not intial
            if((row==0||col==0||row==m-1||col==n-1)&&steps!=0) {
                cout<<row<<" "<<col<<endl;
                return steps;
            }
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0&&ncol>=0&&nrow<m&&ncol<n&&maze[nrow][ncol]=='.'){
                    q.push({steps+1,{nrow,ncol}});
                    maze[nrow][ncol]='+';
                }
            }
        }
        // couldn't find any exit
        return -1;
    }
};