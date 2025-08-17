class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0; // endWord must be in wordList

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord); // avoid revisiting

        while (!q.empty()) {
            string Word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (Word == endWord) return steps;

            for (int i = 0; i < Word.size(); i++) {
                char original = Word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    Word[i] = ch;
                    if (st.find(Word) != st.end()) {
                        q.push({Word, steps + 1});
                        st.erase(Word); // mark as visited
                    }
                }
                Word[i] = original; // restore original character
            }
        }

        return 0; // no transformation found
    }
};