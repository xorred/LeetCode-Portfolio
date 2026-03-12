
# Find All Duplicates in an Array (LeetCode #442)

## 📌 Problem Overview
Given an integer array `nums` of length $n$ where all the integers are in the range $[1, n]$ and each integer appears at most twice, return an array of all the integers that appear twice.

## 🚀 The Optimized Approach: Negative Marking
The challenge requires **$O(n)$ time** and **$O(1)$ auxiliary space**. While a Hash Map is easier to implement, it uses $O(n)$ space.

### The Logic
Because the input values are constrained to $[1, n]$, we can treat the array itself as a frequency tracker:
1. Iterate through the array.
2. For each number `x`, treat its absolute value as an index: `index = abs(x) - 1`.
3. Check the value at `nums[index]`:
   - If it's **negative**, it means we've encountered this index before. The current number `abs(x)` is a duplicate!
   - If it's **positive**, multiply it by `-1` to mark it as "seen."

### Complexity Analysis
- **Time Complexity:** $O(n)$ — We traverse the array exactly once.
- **Space Complexity:** $O(1)$ — We reuse the input array for marking. No extra data structures are used (excluding the output vector).

---

## 🛠️ Implementation Snippet (C++)
```cpp
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) 
            ans.push_back(abs(nums[i]));
        else 
            nums[index] = -nums[index];
    }
    return ans;
}
