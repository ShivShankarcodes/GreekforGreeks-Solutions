## 01. Reverse first K of a Queue

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1)

### Problem Description

**Task:** Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.
Only following standard operations are allowed on queue.
enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
The above operations represent the general processings.
In-built functions of the respective languages can be used to solve the problem.
If the size of queue is smaller than the given k , then return the original queue.

#### Examples

##### Example 1

- **Input:**
```text
q = [1, 2, 3, 4, 5], k = 3Output: [3, 2, 1, 4, 5]Explanation: After reversing the first 3 elements from the given queue the resultant queue will be [3, 2, 1, 4, 5]
```

##### Example 2

- **Input:**
```text
q = [4, 3, 2, 1], k = 4Output: [1, 2, 3, 4] Explanation: After reversing the first 4 elements from the given queue the resultant queue will be [1, 2, 3, 4]
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-29 00:16:11
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        int n= q.size();
        if(k>n) return q;       
        stack<int> st;
        for(int i=0;i<k;i++){
            st.push(q.front());
            q.pop();
        }
        while(st.size() > 0){
            q.push(st.top());
            st.pop();
        }
        for(int i=0;i<n-k;i++){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};
```

*Generated on: 29/10/2026, 12:16:32 am*