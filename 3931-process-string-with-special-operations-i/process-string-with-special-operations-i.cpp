class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string ans="";
        for(char ch:s){
            if(ch=='*'&& ans.size()>=1)ans.pop_back();
            else if(ch=='#' && ans.size()>=1){
                string temp=ans;
                ans+=temp;

            }else if (ch=='%') reverse(ans.begin(),ans.end());
            if(ch>='a'&& ch<='z')ans+=ch;
        }
        return ans;
    }
};