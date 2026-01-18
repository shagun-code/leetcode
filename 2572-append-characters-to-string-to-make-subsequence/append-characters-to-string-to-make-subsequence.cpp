class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                j=j+1;
                i+=1;
            }else{
                i=i+1;
            }
        }
        return t.size()-j;
    }
};