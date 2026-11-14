## 01. Aggressive Cows

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/aggressive-cows/1)

### Problem Description

**Task:** Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct. There are k aggressive cows.Assign the cows to the stalls such that the minimum distance between any two cows is maximized.Examples:Input: arr[] = [1, 2, 4, 8, 9], k = 3

#### Examples

##### Example 1

- **Output:**
```text
4
```
- **Explanation:** The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), which is the maximum possible among all valid arrangements.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log m)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-14 22:35:16
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    bool isPossible(vector<int>& arr, int k,int n,int minDis){
        int cows = 1 , lastPos = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i] - lastPos >= minDis){
                cows++;
                lastPos = arr[i];
            }
          if(cows == k) return true;   
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        int ans = 0;
        int st = 1 , end = arr[n-1]-arr[0];
        while(st <= end){
            int mid = st + (end- st)/2;
            if(isPossible(arr,k,n,mid)){
                ans = mid;
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};
```

*Generated on: 14/11/2026, 10:35:25 pm*