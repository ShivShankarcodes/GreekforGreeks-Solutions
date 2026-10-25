## 01. Next Smaller Element

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1)

### Problem Description

**Task:** You are given an integer array arr[ ]. For every element in the array, your task is to find its Next Smaller Element (NSE). The Next Smaller Element (NSE) of an element x is the first element that appears to the right of x in the array and is strictly smaller than x.If no such element exists, assign -1 as the NSE for that position.Examples:Input: arr[] = [4, 8, 5, 2, 25]

#### Examples

##### Example 1

- **Output:**
```text
[1, -1]
```
- **Explanation:** 4 will be updated to 1 and 1 will be updated to -1.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-23 13:35:54
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
                vector<int> ans(n,-1);
                stack<int> st;
                for(int i=n-1;i>=0;i--){
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

*Generated on: 25/10/2026, 2:18:10 pm*