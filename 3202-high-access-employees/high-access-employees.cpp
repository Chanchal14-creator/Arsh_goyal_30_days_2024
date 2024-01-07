
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        map<string,vector<int>>m;
        int k=0;
        vector<string>ans;
        for(int i=0;i<at.size();i++)
        {
            m[at[i][0]].push_back(stoi(at[i][1]));
        }

        for(auto[x,y]:m)
        {
            if(y.size()>=3)
            {
                sort(y.begin(),y.end());
                for( int i =2 ;i <y.size();i++)
                {
                    int min2 =y[i]%100;
                    int hr2 = y[i]/100;
                    int min1 = y[i-2]%100;
                    int hr1= y[i-2]/100;
                    if(hr1==hr2){
                    ans.push_back(x);
                    break;
                    }
                    else if (hr2-hr1==1&& min2<min1)
                    {
                        ans.push_back(x);
                        break;
                    }
                    
                }
            }

        }
        return ans;
        
    }
};