
#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> leftMaxHeap; // Stores the lower half
    std::priority_queue<int, std::vector<int>, std::greater<int>> rightMinHeap; // Stores the upper half

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // Step 1: Add to max-heap
        leftMaxHeap.push(num);
        
        // Step 2: Ensure all elements in leftMaxHeap <= rightMinHeap
        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();
        
        // Step 3: Maintain size property: leftMaxHeap size >= rightMinHeap size
        if (leftMaxHeap.size() < rightMinHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        if (leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top();
        }
        return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
    }
};