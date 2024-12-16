from typing import List

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        # Perform the operation k times
        for _ in range(k):
            # Initialize minIndex to 0 (index of the first element)
            minIndex = 0
            
            # Traverse the entire nums array to find the index of the smallest element
            for index in range(len(nums)):
                # Update minIndex if we find a smaller element
                minIndex = index if nums[index] < nums[minIndex] else minIndex 
            
            # Multiply the smallest element by the multiplier
            nums[minIndex] *= multiplier
        
        # Return the modified nums array after k operations
        return nums