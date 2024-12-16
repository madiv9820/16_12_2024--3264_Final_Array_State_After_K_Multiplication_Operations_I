#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // Create a max-heap (priority queue) to store elements in the form of (value, index).
        // The value is negated to simulate a min-heap behavior by using a max-heap, since by default,
        // the priority_queue sorts elements in descending order.
        priority_queue<pair<int, int>> pq;
        
        // Populate the priority queue with pairs of (negated_value, negated_index)
        // so that the smallest element will have the highest priority.
        for(int index = 0; index < nums.size(); ++index) {
            pq.push({-nums[index], -index});
        }

        // Perform the operation k times.
        while(k--) {
            // Get the smallest element (the one with the largest negated value) and its index.
            // Negate the index to get the original index back.
            int minIndex = -pq.top().second;
            pq.pop();

            // Multiply the smallest element by the multiplier.
            nums[minIndex] *= multiplier;

            // Push the updated element back into the priority queue with its new value and the same index.
            pq.push({-nums[minIndex], -minIndex});
        }

        // Return the modified array after k operations.
        return nums;
    }
};

int main() {
    vector<vector<int>> nums = {{2,1,3,5,6},{1,2}};
    vector<int> k = {5, 3};
    vector<int> multiplier = {2, 4};
    vector<vector<int>> output = {{8,4,6,5,6},{16,8}};
    Solution sol;

    for(int index = 0; index < nums.size(); ++index) {
        vector<int> result = sol.getFinalState(nums[index], k[index], multiplier[index]);
        bool matched = true;

        for(int i = 0; i < result.size(); ++i)
            if(result[i] != output[index][i]) {matched = false; break; }
        
        cout << (matched ? "true": "false") << endl;
    }
}