## 01. Nodes at K Distance from Root

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/k-distance-from-root/1)

### Problem Description

**Task:** Given a root of binary tree having n nodes and an integer k, return all nodes that are at distance k from the root (root is considered at distance 0 from itself). Nodes should be returned from left to right.

#### Examples

##### Example 1

- **Input:**
```text
k = 0, root = [1, 3, 2]Output: 1Explanation: 1 is the only node which is 0 distance from the root 1.
```

##### Example 2

- **Input:**
```text
k = 3, root = [1, 2, N, N, 1, 5, 3]
```
- **Output:**
```text
5 3Explanation: 5 and 3 are the nodes which are at distance 3 from the root 1, returned from left to right.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(min(k, Height of the Tree))

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-08 18:29:09
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
   
   void preorder(Node* root,vector<int>& ans , int level ,int& k){
       if(root == NULL) return;
       if(level == k) 
            ans.push_back(root->data);
        preorder(root->left,ans,level+1,k);
        preorder(root->right,ans,level+1,k);
   }
    vector<int> kdistance(Node *root, int k) {
         vector<int> ans;
         preorder(root,ans,0,k);
         return ans;
        
    }
};
```

*Generated on: 8/11/2026, 6:30:55 pm*