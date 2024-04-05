class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        st.push(s[0]);
        auto it=s.begin()+1;
        while(it!=s.end())
        {
            
            if(!st.empty()&&abs(st.top()-(*it))==32)
            st.pop();
            else
            st.push(*it);
            it++;
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};