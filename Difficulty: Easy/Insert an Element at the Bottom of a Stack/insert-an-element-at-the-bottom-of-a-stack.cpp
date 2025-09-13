// User function Template for C++

class Solution {
  public:
  
  // Helper function to insert at bottom recursively
  void solve(stack<int>& s, int x) {
      // Base case: if stack is empty, push x
      if (s.empty()) {
          s.push(x);
          return;
      }

      int num = s.top();  // Save top element
      s.pop();            // Remove it
      solve(s, x);        // Recursive call
      s.push(num);        // Restore element after recursion
  }

  // Main function to be called
  stack<int> insertAtBottom(stack<int> st, int x) {
      solve(st, x);       // Fix: use 'st' not 'stack'
      return st;          // Fix: 'retrun' → 'return'
  }
};