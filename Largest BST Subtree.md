## 01. Largest BST Subtree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-bst/1)

### Problem Description

**Task:** Given the root of a binary tree, find the size of the largest subtree that is also a Binary Search Tree (BST). A subtree is considered a BST if, for every node in the subtree:All nodes in its left subtree have values less than the node's value.All nodes in its right subtree have values greater than the node's value.The subtree contains no duplicate values.Return the number of nodes in the largest BST subtree.Note: The size of a subtree is the total number of nodes it contains.Examples :Input: root = [5, 2, 4, 1, 3]Output: 3Explanation:The following sub-tree is a BST of size 3Input: root = [6, 7, 3, N, 2, 2, 4]Output: 3Explanation: The following sub-tree is a BST of size 3:

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(h)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-19 00:36:58
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
  public:
  
    int maxSize;
    
    class Quad {
        public:
            long long max;
            long long min;
            bool isBST;
            int size;
    };
    
    Quad largest(Node* root){
        if(root == NULL) 
            return {LLONG_MIN , LLONG_MAX , true , 0};
            
        Quad left = largest(root->left);
        Quad right = largest(root->right);
        
        long long val = root->data;
        long long mx = max(val,max(left.max,right.max));
        long long mn = min(val,min(left.min,right.min));
        bool isBST = (val > left.max && val < right.min && left.isBST && right.isBST);
        int size = 1 + left.size + right.size;
        
        if(isBST) maxSize = max(maxSize , size);
        return {mx , mn, isBST , size};
    }
    
    int largestBst(Node *root) {
        maxSize = 0;
        largest(root);
        return maxSize;
    }
};
```

*Generated on: 19/11/2026, 12:36:49 am*