import heapq
from typing import List

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        # Create a list of tuples (num, index) where 'num' is the number in nums and 'index' is its position
        num_With_Index = [(num, index) for index, num in enumerate(nums)]
        
        # Convert the list into a heap (priority queue), where the smallest element is at the root
        heapq.heapify(num_With_Index)

        # Perform the operation k times
        for _ in range(k):
            # Pop the smallest element from the heap, this returns a tuple (num, index)
            num, minIndex = heapq.heappop(num_With_Index)
            
            # Multiply the smallest element by the multiplier and update nums at minIndex
            nums[minIndex] *= multiplier
            
            # Push the updated element (new value, same index) back into the heap
            heapq.heappush(num_With_Index, (nums[minIndex], minIndex))
                    
        # Return the modified nums array after k operations
        return nums