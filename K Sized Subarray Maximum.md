## 01. K Sized Subarray Maximum

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1)

### Problem Description

**Task:** Given an array arr[] of positive integers and an integer k. Find the maximum value for each contiguous subarray of size k. Return an array of maximum values corresponding to each contiguous subarray.Examples:Input: arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3

#### Examples

##### Example 1

- **Output:**
```text
[5, 1, 3, 4, 2]
```
- **Explanation:** When k = 1, each element in the array is its own subarray, so the output is simply the same array

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(k)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-25 17:12:07
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        // next greatest element (index)
        stack<int> st;
        vector<int> nge(n,-1);
        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && arr[st.top()] <= arr[i]) st.pop();
            if(st.size() != 0) nge[i] = st.top();
            st.push(i);
        }
        
        vector<int> ans(n-k+1);
        int j=0;
        for(int i=0;i<n-k+1;i++){
            if(j<i) j=i;
            while(nge[j] != -1 && nge[j] < i+k) 
                j = nge[j];
            ans[i] = arr[j];
        }
        return ans;
    }
};
```

*Generated on: 25/10/2026, 5:12:34 pm*