## 01. Previous Smaller Element

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/previous-smaller-element/1)

### Problem Description

**Task:** You are given an integer array arr[ ]. The task is to find Previous Smaller Element (PSE) for every element in the array. The Previous Smaller Element (PSE) of an element x is the first element that appears to the left of x in the array and is strictly smaller than x.

> **Note:** If no such element exists, assign -1 as the PSE for that position.

#### Examples

##### Example 1

- **Input:**
```text
arr[] = [1, 6, 2]Output: [-1, 1, 1]Explanation:For 1, there is no element on the left, so answer is -1.For 6, previous smaller element is 1.For 2, previous smaller element is 1.
```

##### Example 2

- **Input:**
```text
arr[] = [1, 5, 0, 3, 4, 5]Output: [-1, 1, -1, 0, 3, 4]Explanation:For 1, no element on the left, so answer is -1.For 5, previous smaller element is 1.For 0, no element on the left smaller than 0, so answer is -1.For 3, previous smaller element is 0.For 4, previous smaller element is 3.For 5, previous smaller element is 4.
```

#### Constraints

- **1.** `1 ≤ arr.size() ≤ 10⁵¹ ≤ arr[i] ≤ 10⁵`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-23 13:38:32
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
                        vector<int> ans(n,-1);
                        stack<int> st;
                        for(int i=0;i<n;i++){
                            // pop
                            while(st.size() > 0 && st.top() >= arr[i]) 
                                st.pop();
                            // mark
                            if(st.size() != 0) ans[i] = st.top();
                            // push
                            st.push(arr[i]);
                        }
                        return ans;
    }
};
```

*Generated on: 25/10/2026, 2:20:09 pm*