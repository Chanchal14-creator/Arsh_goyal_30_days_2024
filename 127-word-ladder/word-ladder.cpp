class Solution {
public:
    int cmp(string str1,string str2)
    {
        int ans=0;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i])
            ans++;
        }
    return ans;
    }
    int ladderLength(string startgene, string endgene, vector<string>& bank) {
        map<int,vector<int>>m;
        int n=bank.size();
        bool proceed=false;
        for(int i=0;i<n;i++)
        {
            if(bank[i]==endgene)
            proceed=true;
            if(cmp(startgene,bank[i])==1)
            m[-1].push_back(i);
        }
        if(!proceed)
        return 0;
        for(int k=0;k<n;k++)
        {
           
            for(int j=k+1;j<n;j++)
            {
                if(cmp(bank[k],bank[j])==1)
                {
                    m[k].push_back(j);
                    m[j].push_back(k);
                }
            }
            
        }
       
        for(auto [x,y]:m)
        {cout<<x<<":";
            for(int i=0;i<y.size();i++)
            {
                cout<<y[i]<<" ";
            }
            cout<<endl;
            
        }
            
            vector<int>visit(n+1,0);
            queue<int>q;
            int depth=1;
            for(auto x : m[-1]) 
            {
               
                if (bank[x] == endgene) {
                   
                    return ++depth;
                } 
                else if (visit[x] == 0) {
                    q.push(x);
                }
            }

            while(!q.empty())
            {
                
                int len=q.size();
                depth++;
                for(int i=0;i<len;i++)
                {
                    visit[q.front()+1]=1;
                    for(auto x:m[q.front()])
                    {
                      
                        cout<<bank[x];
                        if(bank[x]==endgene)
                        return ++depth;
                        else if(visit[x+1]==0)
                        {
                            q.push(x);
                        }
                    }
                    q.pop();
                }

            }
        
        return 0;
    }
};