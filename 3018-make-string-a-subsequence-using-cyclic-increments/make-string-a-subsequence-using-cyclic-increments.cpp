class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(str1[i]=='z' && str2[j]=='a')
            {
                j++;
                if(j==str2.size())
            return true;
                cout<<"hello";
            }
            else if( str2[j]-str1[i]==1||str2[j]-str1[i]==0)
            {
            j++;
            if(j==str2.size())
            return true;
            cout<<"hi";
            }
            
        }
       

        return false;
    }
};