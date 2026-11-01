## 01. Queue using Stack

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/queue-using-stack/1)

### Problem Description

**Task:** Implement a Queue using stacks. You are allowed to use only stack data structures to implement the queue.The Queue must support the following operations:(i) enqueue(x): Insert an element x at the rear of the queue.(ii) dequeue(): Remove the element from the front of the queue.(iii) front(): Return the front element if the queue is not empty, else return -1.(iv) size(): Return the number of elements currently in the queue.There will be a sequence of queries represented by 2d array queries[][]. The queries are represented in numeric form:1 x : Call enqueue(x)2: Call dequeue()3: Call front()4: Call size()You just have to implement the functions enqueue, dequeue, front and size. The driver code will handle the input and output.Examples:Input: queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [4], [3]]

#### Examples

##### Example 1

- **Output:**
```text
[-1, 0]
```
- **Explanation:** Queries on queue are as follows:front(): Queue is empty, return -1.size(): Queue contains 0 elements return 0.enqueue(10): Insert 10 at the rear (no output for enqueue).

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-01 21:35:55
- **Status:** Correct
- **Marks:** 2

```cpp
class myQueue {
    stack<int> st1;
    stack<int> st2;
    int length ;
  public:
    myQueue() {
        length = 0;
    }

    void enqueue(int x) {
        st1.push(x);
        length++;
    }

    void dequeue() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        st2.pop();
        length--;
    }

    int front() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        if(st2.empty()) return -1;
        return st2.top();
    }

    int size() {
        return length;
    }
};
```

*Generated on: 1/11/2026, 9:36:23 pm*