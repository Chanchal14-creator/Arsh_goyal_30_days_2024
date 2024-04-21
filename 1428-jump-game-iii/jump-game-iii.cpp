class Solution {

public:
    bool canReach(vector<int>& arr, int start) {
        int N=arr.size();
        vector<int> v(N,0);
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int node=q.front();q.pop();
                v[node]=1;
                if(arr[node]==0) return true;
                if(node-arr[node]>=0 && !v[node-arr[node]]) 
                    q.push(node-arr[node]);
                if(node+arr[node]<N && !v[node+arr[node]]) 
                    q.push(node+arr[node]);
            }
        }
        return false;
    }
};
    
