## 01. Painter's Partition Problem

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1)

### Problem Description

**Task:** Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.Each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).Find the minimum amount of time required to paint all the boards.Examples:Input: arr[] = [5, 10, 30, 20, 15], k = 3

#### Examples

##### Example 1

- **Output:**
```text
1000
```
- **Explanation:** There is only one painter, so the painter must paint all boards sequentially. The total time taken will be the sum of all board lengths, i.e., 100 + 200 + 300 + 400 = 1000.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n * log(sum(arr)))
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-14 20:13:23
- **Status:** Correct
- **Marks:** 8

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
    int minTime(vector<int>& arr, int k) {
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

*Generated on: 14/11/2026, 8:14:02 pm*