## 01. Histogram Max Rectangular Area

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1)

### Problem Description

**Task:** Given a histogram represented by an array arr[], where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.
Find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.

#### Examples

##### Example 1

- **Input:**
```text
arr[] = [60, 20, 50, 40, 10, 50, 60]
```
- **Output:**
```text
100
```
- **Explanation:** We get the maximum by picking bars highlighted above in green (50, and 60). The area is computed = 50 * 2 = 100.

##### Example 2

- **Input:**
```text
arr[] = [3, 5, 1, 7, 5, 9]
```
- **Output:**
```text
15
```
- **Explanation:** We get the maximum by picking bars 7, 5 and 9. The area is computed = 5 * 3 = 15.

##### Example 3

- **Input:**
```text
arr[] = [3]
```
- **Output:**
```text
3
```
- **Explanation:** In this example the largest area would be 3 of height 3 and width 1.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (2)

#### Solution 1 (C++)

- **Submitted:** 2026-10-25 13:35:39
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Method 2
        int n = arr.size();
        int maxArea = 0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            int currHeight = (i == n) ? 0 : arr[i];
            while( st.size() > 0 && arr[st.top()] > currHeight) {
                int h = arr[st.top()];
                st.pop();
                int w = st.empty() ? i : (i-st.top()-1);
                int area = h * w;
                maxArea = max(area,maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-10-25 12:48:36
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // code here
        int n = arr.size();
        // next smaller element (index)
        stack<int> st;
        vector<int> nsi(n);
        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();
            if(st.size() != 0) nsi[i] = st.top();
            else nsi[i] = n;
            st.push(i);
        }
        
        // previous smaller element (index)
        while(st.size() > 0) st.pop();
        vector<int> psi(n);
        for(int i=0;i<n;i++){
            while(st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();
            if(st.size() != 0) psi[i] = st.top();
            else psi[i] = -1;
            st.push(i);
        }
        
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int height = arr[i];
            int width = nsi[i] - psi[i] - 1;
            int area = height * width;
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};
```

*Generated on: 25/10/2026, 2:14:57 pm*