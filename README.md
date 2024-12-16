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