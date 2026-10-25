## 01. Get Min from Stack

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1)

### Problem Description

**Task:** Implement a class SpecialStack that supports following operations:
push(x) – Insert an integer x into the stack.
pop() – Remove the top element from the stack.
peek() – Return the top element from the stack. If the stack is empty, return -1.
getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
isEmpty() – Return true if stack is empty, else false
There will be a sequence of queries queries[][]. The queries are represented in numeric form:
1 x : Call push(x)
2: Call pop()
3: Call peek()
4: Call getMin()
5: Call isEmpty()
The driver code will process the queries, call the corresponding functions, and print the outputs of peek(), getMin(), isEmpty() operations.You only need to implement the above five functions.

#### Examples

##### Example 1

- **Input:**
```text
q = 7, queries[][] = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
```
- **Output:**
```text
[3, 2, 1] push(2): Stack is [2] push(3): Stack is [2, 3] peek(): Top element is 3 pop(): Removes 3, stack is [2] getMin(): Minimum element is 2 push(1): Stack is [2, 1] getMin(): Minimum element is 1
```

##### Example 2

- **Input:**
```text
q = 5, queries[][] = [[1, 4], [1, 2], [4], [3], [5]]
```
- **Output:**
```text
[2, 2, false]
```
- **Explanation:** push(4): Stack is [4] push(2): Stack is [4, 2]getMin(): Minimum element is 2peek(): Top element is 2isEmpty(): false

#### Constraints

- **1.** `1 ≤ q ≤ 10⁵⁰ ≤ values on the stack ≤ 10⁹`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-25 14:45:18
- **Status:** Correct
- **Marks:** 4

```cpp
class SpecialStack {
    stack<int> st;
    stack<int> minSt;
  public:
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        st.push(x);
        if( minSt.size() == 0 || x <= minSt.top()) minSt.push(x);
    }

    void pop() {
        if(st.size() == 0) return;
        if(st.top() == minSt.top()) minSt.pop();
        st.pop();
    }

    int peek() {
        return st.size() > 0 ? st.top() : -1;
    }

    bool isEmpty() {
        return st.size() > 0 ? false : true;
    }

    int getMin() {
        return minSt.size() > 0 ? minSt.top() : -1;
    }
};
```

*Generated on: 25/10/2026, 2:45:40 pm*