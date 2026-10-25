## 01. Next Greater Element

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1)

### Problem Description

**Task:** You are given an array arr[] of integers, the task is to find the next greater for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.If there does not exist next greater of current element, then next greater element for current element is -1.ExamplesInput: arr[] = [1, 3, 2, 4]

#### Examples

##### Example 1

- **Output:**
```text
[3, 4, 4, -1]
```
- **Explanation:** The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.

##### Example 2

- **Input:**
```text
arr[] = [6, 8, 0, 1, 3]
```
- **Output:**
```text
[-1, -1, -1, -1]
```
- **Explanation:** There is no next greater element for any of the elements in the array, so all are -1.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-23 13:34:27
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            // pop
            while(st.size() > 0 && st.top() <= arr[i]) 
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

*Generated on: 25/10/2026, 2:17:12 pm*