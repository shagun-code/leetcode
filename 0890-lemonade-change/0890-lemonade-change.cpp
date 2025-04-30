#include <vector>

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        int five = 0, ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;  // Accept $5 bill
            } else if (bill == 10) {
                if (five > 0) {
                    five--;  // Give one $5 as change
                    ten++;   // Store the $10 bill
                } else {
                    return false; // Not enough change
                }
            } else { // When bill is $20
                if (ten > 0 && five > 0) { // Prefer to give $10 + $5
                    ten--;
                    five--;
                } else if (five >= 3) { // Otherwise, give three $5 bills
                    five -= 3;
                } else {
                    return false; // Not enough change
                }
            }
        }
        return true;
    }
};