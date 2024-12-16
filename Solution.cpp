#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // Perform the operation k times.
        while(k--) {
            // Variable to store the index of the smallest element in the array.
            int minIndex = 0;
            
            // Traverse the array to find the index of the smallest element.
            for(int index = 0; index < nums.size(); ++index)
                // Update minIndex if a smaller element is found at the current index.
                minIndex = (nums[index] < nums[minIndex]) ? index : minIndex;
            
            // Multiply the smallest element by the multiplier.
            nums[minIndex] *= multiplier;
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