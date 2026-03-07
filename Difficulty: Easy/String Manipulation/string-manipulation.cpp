class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        stack<string> s;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            if(s.empty()) {
                s.push(arr[i]);
            }
            else if(s.top() == arr[i]) {
                s.pop();
            }
            else {
                s.push(arr[i]);
            }
        }
        
        return s.size();
    }
};