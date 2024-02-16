class Solution {
public:
 static bool cmp (pair<int,int> &a , pair<int,int> &b )
{
    return a.second<b.second;
}
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>A;
        for(int i=0;i<arr.size();i++)
        {
            A[arr[i]]++;
        }
        vector<pair<int,int>>p;
        for(auto x:A)
        {
            p.push_back({x.first,x.second});
        }
        
        sort(p.begin(), p.end(), cmp); 
        int ans=0;
        int y=0;
        for(auto x:p)
        {
            if(k-x.second>=0)
            {
                k-=x.second;
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};