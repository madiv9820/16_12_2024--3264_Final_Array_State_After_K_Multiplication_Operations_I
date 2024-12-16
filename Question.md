# [3264. Final Array State After K Multiplication Operations I](https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i?envType=daily-question&envId=2024-12-16)

**Type:** Easy <br>
**Topics:** Array, Math, Heap (Priority Queue), Simulation <br>
**Companies:** Amazon
<hr>

You are given an integer array `nums`, an integer `k`, and an integer `multiplier`.

You need to perform `k` operations on `nums`. In each operation:
- Find the **minimum** value `x` in `nums`. If there are multiple occurrences of the minimum value, select the one that appears **first**.
- Replace the selected minimum value `x` with `x * multiplier`.

Return an integer array denoting the *final state* of `nums` after performing all `k` operations.
<hr>

### Examples:

- **Example 1:** <br>
**Input:** nums = [2,1,3,5,6], k = 5, multiplier = 2 <br>
**Output:** [8,4,6,5,6] <br>
**Explanation:** 

    | Operation     | Result            |
    |---------------|-------------------|
    | After operation 1 | [2, 2, 3, 5, 6]  |
    | After operation 2 | [4, 2, 3, 5, 6]  |
    | After operation 3 | [4, 4, 3, 5, 6]  |
    | After operation 4 | [4, 4, 6, 5, 6]  |
    | After operation 5 | [8, 4, 6, 5, 6]  |

- **Example 2:** <br>
**Input:** nums = [1,2], k = 3, multiplier = 4 <br>
**Output:** [16,8] <br>
**Explanation:** 

    | Operation        | Result   |
    |------------------|----------|
    | After operation 1 | [4, 2]  |
    | After operation 2 | [4, 8]  |
    | After operation 3 | [16, 8] |

<hr>

### Constraints:
- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`
- `1 <= k <= 10`
- `1 <= multiplier <= 5`
<hr>

### Hints:
- Maintain sorted pairs `(nums[index], index)` in a priority queue.
- Simulate the operation k times.