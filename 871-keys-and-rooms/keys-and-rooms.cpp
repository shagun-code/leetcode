
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;   // keeps track of visited rooms
        stack<int> pocket;            // stack to hold keys (rooms to visit)

        pocket.push(0);               // start with room 0

        while (!pocket.empty()) {
            int i = pocket.top();     // take a key from the pocket
            pocket.pop();

            if (visited.find(i) != visited.end()) {
                continue;             // skip if already visited
            }

            visited.insert(i);        // mark room as visited

            // add all keys from this room to the pocket
            for (int j : rooms[i]) {
                if (visited.find(j) == visited.end()) {
                    pocket.push(j);
                }
            }
        }

        return visited.size() == n;   // true if all rooms visited
    }
};