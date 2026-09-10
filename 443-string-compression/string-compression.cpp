
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int index = 0;

        while (i < n) {
            char curr_char = chars[i]; // Fixed: changed 'char[i]' to 'chars[i]'
            int count = 0;

            // Count occurrences of curr_char
            while (i < n && chars[i] == curr_char) {
                count++;
                i++;
            }

            // Write character to array
            chars[index] = curr_char; // Fixed: changed 'char[index]' to 'chars[index]'
            index++;

            // Write count digits if > 1
            if (count > 1) {
                string count_str = to_string(count);
                for (char ch : count_str) {
                    chars[index] = ch; // Fixed: changed 'char[index]' to 'chars[index]'
                    index++;
                }
            }
        }

        return index;
    }
};