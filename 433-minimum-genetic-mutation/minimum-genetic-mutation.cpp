class Solution {
public:
    int cmp(string str1,string str2)
    {
        int ans=0;
        for(int i=0;i<8;i++)
        {
            if(str1[i]!=str2[i])
            ans++;
        }
        return ans;
    }

    int minMutation(string startgene, string endgene, vector<string>& bank) {
        map<int,vector<int>>m;
        int n=bank.size();
        
        for(int i=0;i<n;i++)
        {
            if(cmp(startgene,bank[i])==1)
            m[-1].push_back(i);
        }
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
                cout << "3" << bank[x];
                if (bank[x] == endgene) {
                    cout << "3" << bank[x];
                    return depth;
                } 
                else if (visit[x] == 0) {
                    cout<<x;
                    q.push(x);
                }
            }

            while(!q.empty())
            {
                cout<<"1";
                int len=q.size();
                depth++;
                for(int i=0;i<len;i++)
                {cout<<"2";
                    visit[q.front()+1]=1;
                    for(auto x:m[q.front()])
                    {
                        cout<<"3";
                        if(bank[x]==endgene)
                        return depth;
                        else if(visit[x+1]==0)
                        {
                            q.push(x);
                        }
                    }
                    q.pop();
                }

            }
        
        return -1;
    }
};