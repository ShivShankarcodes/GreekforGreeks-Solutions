## 01. Allocate Minimum Pages

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)

### Problem Description

**Task:** Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:
Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
All books must be allocated.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum. If it is not possible to allocate books to all students, return -1;

#### Examples

##### Example 1

- **Input:**
```text
arr[] = [12, 34, 67, 90], k = 2
```
- **Output:**
```text
113
```
- **Explanation:** Allocation can be done in following ways: = > [12] and [34, 67, 90] Maximum Pages = 191 = > [12, 34] and [67, 90] Maximum Pages = 157 = > [12, 34, 67] and [90] Maximum Pages = 113.The third combination has the minimum pages assigned to a student which is 113.

##### Example 2

- **Input:**
```text
arr[] = [15, 17, 20], k = 5Output: -1Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O( n × log(sum(arr)))
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-12 23:19:37
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
  
    bool isValid(vector<int> &arr, int k,int n, long long mid){
        int student = 1 ;
        long long pages = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > mid) return false;
            if(pages + arr[i] <= mid){
                pages += arr[i];
            }else{
                student++;
                pages = arr[i];
            }
        }
        if(student > k) return false;
        else return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(k>n) return -1;
        
       long long sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        long long ans = -1;
        long long start = 0 , end = sum;
        while(start <= end){
            long mid = start + (end - start)/2;
            if(isValid(arr , k, n, mid)){
                ans = mid;
               end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return (int)ans;
    }
};
```

*Generated on: 12/11/2026, 11:59:38 pm*