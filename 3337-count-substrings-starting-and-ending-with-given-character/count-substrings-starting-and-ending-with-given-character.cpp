class Solution {
public:
    long long countSubstrings(string s, char c) {
       long long count=0;
       long long substring=0;
       for(char &ch:s){
        if(ch==c){
            substring+=(1+count);
            count++;
        }
       } 
       return substring;
    }
};