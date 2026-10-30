## 01. Interleave the First Half of the Queue with Second Half

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1)

### Problem Description

**Task:** Given a queue q of even size, rearrange the queue by interleaving its first half with the second half.Interleaving is the process of mixing two sequences by alternating their elements while preserving their relative order.In other words, Interleaving means place the first element from the first half and then first element from the 2nd half and again second element from the first half and then second element from the 2nd half and so on.Examples:Input: q = [2, 4, 3, 1]

#### Examples

##### Example 1

- **Output:**
```text
[2, 3, 4, 1]
```
- **Explanation:** We place the first element of the first half 2 and after that place the first element of second half 3 and after that repeat the same process one more time so the resulting queue will be [2, 3, 4, 1]Input: q = [3, 5]Output: [3, 5]Explanation: We place the first element of the first half 3 and first element of the second half 5 so the resulting queue is [3, 5]

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-31 00:47:55
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        stack<int> st;
        for(int i=0;i<n/2;i++){
            st.push(q.front());
            q.pop();
        }
        while(st.size() > 0){
            q.push(st.top());
            st.pop();
        }
        for(int i=0;i<n/2;i++){
            st.push(q.front());
            q.pop();
        }
        while(st.size() > 0){
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }
        for(int i=0;i<n;i++){
            st.push(q.front());
            q.pop();
        }
        while(st.size() > 0){
            q.push(st.top());
            st.pop();
        }
    }
};
```

*Generated on: 31/10/2026, 12:48:41 am*