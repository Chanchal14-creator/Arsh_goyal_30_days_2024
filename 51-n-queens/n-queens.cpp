class Solution {
public:

vector<vector<string>> ans;
 void p_t_q(vector<vector<char>>b,int i,int j,int noqn)
 {
    noqn++;
    for(int m=0;m<b.size();m++)
    {
        for(int n=0;n<b.size();n++)
        {
            if(m-n ==i-j)
            b[m][n] = '.';
            else if(m+n == i+j)
            b[m][n] = '.';
            else if(m==i)
            b[m][n]='.';
            else if(n==j)
            b[m][n] = '.';
        }
    }
    b[i][j] = 'Q';
    if(noqn == b.size())
    {
        vector<string>v;
        for(int l=0;l<b.size();l++)
        {
            string str = "";
            for(int k=0;k<b.size();k++)
            {
                str += b[l][k];
            }
            v.push_back(str);
        }
        ans.push_back(v);
        return;
    }
    for(int n=0;n<b.size();n++)
    {
        if(b[i+1][n]=='\0')
        {
            p_t_q(b,i+1,n,noqn);
        }
    }

 }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> b;
        b.resize(n, vector<char>(n, '\0'));
        int noqn=0;
        for(int i=0;i<n;i++)
        {
            p_t_q(b,0,i,noqn);
        }
        return ans;
    }
};