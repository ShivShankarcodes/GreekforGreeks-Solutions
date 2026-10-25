## 01. Stock Span Problem

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1)

### Problem Description

**Task:** The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.
Given an array arr[] representing daily stock prices, the stock span for the i-th day is the number of consecutive days up to day i (including day i itself) for which the price of the stock is less than or equal to the price on day i. Return the span of stock prices for each day in the given sequence.

#### Examples

##### Example 1

- **Input:**
```text
arr[] = [100, 80, 90, 120]
```
- **Output:**
```text
[1, 1, 2, 4]
```
- **Explanation:** Consider each day one by one:Day 1 (100): Span = 1. Day 2 (80): Span = 1 because the previous price (100) is greater than 80. Day 3 (90): Span = 2 because 80 ≤ 90, but 100 > 90. Day 4 (120): Span = 4 because 100, 80, and 90 are all less than or equal to 120. Hence, the output is [1, 1, 2, 4].

##### Example 2

- **Input:**
```text
arr[] = [10, 4, 5, 90, 120, 80]
```
- **Output:**
```text
[1, 1, 2, 4, 5, 1]
```
- **Explanation:** Consider each day one by one:Day 1 (10): Span = 1. Day 2 (4): Span = 1 because the previous price (10) is greater than 4. Day 3 (5): Span = 2 because 4 ≤ 5, but 10 > 5. Day 4 (90): Span = 4 because 10, 4, and 5 are all less than or equal to 90. Day 5 (120): Span = 5 because all previous prices are less than or equal to 120. Day 6 (80): Span = 1 because the previous price (120) is greater than 80. Hence, the output is [1, 1, 2, 4, 5, 1].

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-23 15:26:10
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() > 0 && arr[st.top()] <= arr[i]) st.pop();
            if(st.size() != 0) ans[i] = st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            ans[i] = i-ans[i];
        }
        return ans;
    }
};
```

*Generated on: 25/10/2026, 2:15:56 pm*