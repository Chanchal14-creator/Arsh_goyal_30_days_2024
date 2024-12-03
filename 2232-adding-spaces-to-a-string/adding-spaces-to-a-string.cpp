class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str="";
       int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(k<spaces.size() && spaces[k] == i )
            {
                str += ' ';
                k++;
            }
            str+=s[i];
        }
        return str;
    }
};