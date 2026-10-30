## 01. First Negative in Windows of Size K

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1)

### Problem Description

**Task:** Given an array arr[] and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.Note: If a window does not contain a negative integer, then return 0 for that window.Examples:Input: arr[] = [-8, 2, 3, -6, 10] , k = 2

#### Examples

##### Example 1

- **Output:**
```text
[0, 0] Explanation:Window [12, 1, 3] No negative integers, output is 0. Window [1, 3, 5] No negative integers, output is 0.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(k)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-30 23:15:15
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            if(arr[i] < 0) q.push(i);
        }
        vector<int> ans(n-k+1,0);
        for(int i=0;i<n-k+1;i++){
            while(q.size() > 0 && q.front() < i) q.pop();
            if(q.size() > 0 && q.front() < i+k) ans[i] = arr[q.front()];
        }
        return ans;
    }
};
```

*Generated on: 30/10/2026, 11:15:35 pm*