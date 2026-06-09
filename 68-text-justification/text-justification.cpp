class Solution {
public:
    int MAX_WIDTH;

    string findLine(int i, int j, int extraSpaceGaddha, int eachGaddhaSpace, vector<string>& words, bool isLastLine) {
        string line;
        
        // If it's the last line or the line only contains 1 word, it must be left-justified
        if (isLastLine || (j - i == 1)) {
            for (int k = i; k < j; k++) {
                line += words[k];
                if (k != j - 1) {
                    line += " "; // Exactly 1 space between words
                }
            }
            // Pad the remaining spaces at the end of the line
            while (line.length() < MAX_WIDTH) {
                line += " ";
            }
            return line;
        }

        // Fully justified line logic
        for (int k = i; k < j; k++) {
            line += words[k];
            if (k == j - 1) {
                continue; // Don't add spaces after the last word of the line
            }
            
            // Add the base evenly distributed spaces
            for (int z = 1; z <= eachGaddhaSpace; z++) {
                line += " ";
            }
            
            // Distribute leftover spaces from left to right
            if (extraSpaceGaddha > 0) {
                line += " ";
                extraSpaceGaddha--;
            }
        }
        
        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        MAX_WIDTH = maxWidth;
        int i = 0;
        
        while (i < n) {
            int lettersCount = words[i].length();
            int j = i + 1;
            int gaddhe = 0;
            
            // Greedy approach to pack as many words as possible
            while (j < n && words[j].length() + 1 + gaddhe + lettersCount <= maxWidth) {
                lettersCount += words[j].length();
                gaddhe += 1;
                j++;
            }
            
            int totalSpaces = maxWidth - lettersCount;
            int eachGaddhaSpace = (gaddhe == 0) ? 0 : totalSpaces / gaddhe;
            int extraGaddhe = (gaddhe == 0) ? 0 : totalSpaces % gaddhe;
            
            // Check if this is the last line of the text
            bool isLastLine = (j == n);
            
            result.push_back(findLine(i, j, extraGaddhe, eachGaddhaSpace, words, isLastLine));
            i = j; // Move to the next set of words
        }
        
        return result;
    }
};