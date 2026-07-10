#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // 1. Store all dictionary roots in a hash set for O(1) average lookup
        unordered_set<string> rootSet(dictionary.begin(), dictionary.end());
        
        // 2. Use stringstream to split the sentence into individual words
        stringstream ss(sentence);
        string word;
        string result = "";
        
        // 3. Process every word in the sentence
        while (ss >> word) {
            string prefix = "";
            bool found = false;
            
            // Check every possible prefix of the current word from shortest to longest
            for (int i = 0; i < word.length(); i++) {
                prefix += word[i];
                if (rootSet.count(prefix)) {
                    result += prefix + " ";
                    found = true;
                    break; // Found the shortest root, move to the next word
                }
            }
            
            // If no root matches, keep the original word
            if (!found) {
                result += word + " ";
            }
        }
        
        // Remove the trailing space at the end of the result string
        if (!result.empty()) {
            result.pop_back();
        }
        
        return result;
    }
};