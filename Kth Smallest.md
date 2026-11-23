## 01. Kth Smallest

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1)

### Problem Description

**Task:** Given an integer array arr[] and an integer k, find and return the k^th smallest element in the given array.Examples :Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4Output: 5

#### Examples

##### Example 1

- **Explanation:** 3rd smallest element in the given array is 7.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log k)
- **Expected Auxiliary Space Complexity:** O(k)

### Accepted Solutions (3)

#### Solution 1 (C++)

- **Submitted:** 2026-11-24 00:19:44
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        for(int ele : arr){
            pq.push(ele);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
        
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-11-24 00:07:57
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int ele : arr){
            pq.push(ele);
        }
        for(int i=1;i<k;i++){
            pq.pop();            
        }
        return pq.top();
        
    }
};
```

#### Solution 3 (C++)

- **Submitted:** 2026-10-21 12:36:23
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        sort(arr.begin() , arr.end());
        return arr[k-1];
    }
};
```

*Generated on: 24/11/2026, 12:20:35 am*