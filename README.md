# [3264. Final Array State After K Multiplication Operations I](https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i?envType=daily-question&envId=2024-12-16) (All Approaches)

- ## Approach 1:- Brute Force

    - ### Intuition
        The task is to apply a set of operations on a list of integers (`nums`). Each operation consists of finding the smallest element in the list and multiplying it by a given `multiplier`. This operation is repeated **$k$** times.

        - #### Key Observations:
            1. In each operation, we are always modifying the smallest element in the list.
            2. The order of the numbers is important, as it affects which number gets multiplied.
            3. After applying the operation **$k$** times, the list will reflect the transformations based on the smallest elements repeatedly being scaled by the multiplier.

    - ### Approach
        1. **Initialization**:
            - We are given a list `nums` and need to perform `k` operations, where in each operation:
                - The smallest element in the list is multiplied by the `multiplier`.
        
        2. **Outer Loop**:
            - We loop `k` times, each time applying the operation of finding and modifying the smallest element in the list.
        
        3. **Inner Loop**:
            - Inside the loop, we traverse the entire list to find the index (`minIndex`) of the smallest element.
            - We use a conditional expression (`minIndex = index if nums[index] < nums[minIndex] else minIndex`) to track the index of the smallest element while iterating through the list.

        4. **Update**:
            - After identifying the smallest element, we multiply it by the `multiplier` and update the list.
        
        5. **Return the Final State**:
            - After all `k` operations, the final modified list is returned.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
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
            ```
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity
        - **Inner Loop**: For each operation, the algorithm checks every element in the list to find the smallest one, which takes **$O(n)$** time, where **$n$** is the length of the list `nums`.
        - **Outer Loop**: The outer loop runs `k` times, so the total number of iterations is **$k$**.
        - **Total Complexity**: The time complexity is **$O(k * n)$**, where **$k$** is the number of operations and **$n$** is the length of the list.

    - ### Space Complexity
        - **In-Place Modification**: The algorithm modifies the list in place, meaning we do not use any additional data structures except for a few variables (`minIndex`, `index`).
        - **Total Complexity**: The space complexity is **$O(1)$**, as the space used does not depend on the input size and is constant.

- ## Approach 2:- Min Heap

    - ### Intuition
        We need to repeatedly perform the following operation on a list `nums`:
        1. Find the smallest element in the array.
        2. Multiply this smallest element by a given `multiplier`.

        We need to do this for **$k$** operations. The most efficient way to find the smallest element in the array repeatedly is to use a **priority queue (min-heap)**. By maintaining the elements in a heap, we can access and modify the smallest element in **$O(log(n))$** time, which significantly improves performance compared to linearly searching for the smallest element.

    - ### Approach
        1. **Max-Heap to Simulate Min-Heap**:
            - Since the default priority queue in C++ (`std::priority_queue`) is a max-heap (largest element at the top), we negate the values to simulate a **min-heap** behavior. This ensures that the smallest element (after negation) will have the highest priority.

        2. **Heap Initialization**:
            - We create a priority queue of pairs `(value, index)` where `value` is the element from `nums` and `index` is its original position. Both the `value` and `index` are negated so that the smallest value will be on top of the heap.

        3. **Performing `k` Operations**:
            - For each of the `k` operations, we pop the smallest element from the heap, multiply it by the `multiplier`, and then push the updated element back into the heap.

        4. **Returning the Final State**:
            - After all `k` operations are performed, the list `nums` is modified in place, and we return it.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
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
            ```
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity
        - **Priority Queue Operations**: 
            - Each insert and remove operation on the heap takes **$O(log(n))$** time, where **$n$** is the size of the array.
            - For each of the **$k$** operations, we perform one `pop` and one `push` operation on the priority queue.
        - **Overall Time Complexity**: The total time complexity is **$O(k*log(n))$**.

    - ### Space Complexity
        - **Heap Storage**: 
            - The heap stores all **$n$** elements, each represented as a pair `(value, index)`. This results in a space complexity of **$O(n)$**.
        - **Overall Space Complexity**: The space complexity is **$O(n)$** due to the heap.