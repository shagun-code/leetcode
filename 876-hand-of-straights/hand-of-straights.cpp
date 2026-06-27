class Solution { 
public: 
    bool isNStraightHand(vector<int>& hand, int groupSize) { 
        int n = hand.size(); 
        
        // If the hand cannot be divided equally into groups, return false
        if (n % groupSize != 0) { 
            return false; 
        } 
        
        // Count frequencies of each card
        map<int, int> mp; 
        for (int &handnumber : hand) { 
            mp[handnumber]++; 
        } 
        
        // Process the cards
        while (!mp.empty()) { 
            // Get the smallest available card
            int curr = mp.begin()->first; 
            
            // Check and form a valid consecutive group
            for (int i = 0; i < groupSize; i++) { 
                if (mp[curr + i] == 0) { 
                    return false; 
                } 
                
                mp[curr + i]--; 
                
                if (mp[curr + i] < 1) { 
                    mp.erase(curr + i); 
                } 
            } 
        } 
        return true; 
    } 
};
