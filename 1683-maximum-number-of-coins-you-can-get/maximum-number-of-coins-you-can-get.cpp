class Solution {
public:
    int maxCoins(vector<int>& piles) {
      int n=piles.size();
      sort(begin(piles),end(piles));
      int result=0;
      int Bob=0;
      int M=n-2;
      
      while(M>0 &&  Bob < n / 3){
        result+=piles[M];
        M-=2;
        Bob++;
       
      }
      return result;

    }
};