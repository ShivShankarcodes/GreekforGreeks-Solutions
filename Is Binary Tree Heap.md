## 01. Is Binary Tree Heap

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1)

### Problem Description

**Task:** You are given the root of a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.A binary tree is considered a max-heap if it satisfies the following conditions:Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.Max-Heap Property: The value of each node is greater than or equal to the values of its children.Examples:Input: root = [97, 46, 37, 12, 3, 7, 31, 6, 9]

#### Examples

##### Example 1

- **Output:**
```text
true
```
- **Explanation:** The tree is complete and satisfies the max-heap property.

##### Example 2

- **Input:**
```text
root = [97, 46, 37, 12, 3, 7, 31, N, N, 2, 4] Output: falseExplanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (3)

#### Solution 1 (C++)

- **Submitted:** 2026-11-26 23:55:20
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int size(Node* root){
        if(root == NULL) return 0;
        return 1 + size(root->left) + size(root->right);    
    }
    
    
    
    bool isCBT(Node* root,int idx,int& n){
        if(root == NULL) return true;
        if(root->left != NULL && root->left->data > root->data) return false;
        if(root->right != NULL && root->right->data > root->data) return false;
        if(idx > n) return false;
        return isCBT(root->left,2*idx,n) && isCBT(root->right, 2*idx+1, n);
    }
    
    bool isHeap(Node* root) {
        int n = size(root);
        return isCBT(root,1,n);
        
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-11-26 23:52:32
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int size(Node* root){
        if(root == NULL) return 0;
        return 1 + size(root->left) + size(root->right);    
    }
    
    bool isMaxHeap(Node* root){
        if(root == NULL) return true;
        if(root->left != NULL && root->left->data > root->data) return false;
        if(root->right != NULL && root->right->data > root->data) return false;
        return isMaxHeap(root->left) && isMaxHeap(root->right);
    }
    
    bool isCST(Node* root,int idx,int& n){
        if(root == NULL) return true;
        if(root->left != NULL && root->left->data > root->data) return false;
        if(root->right != NULL && root->right->data > root->data) return false;
        if(idx > n) return false;
        return isCST(root->left,2*idx,n) && isCST(root->right, 2*idx+1, n);
    }
    
    bool isHeap(Node* root) {
        int n = size(root);
        return isMaxHeap(root) && isCST(root,1,n);
        
    }
};
```

#### Solution 3 (C++)

- **Submitted:** 2026-11-26 23:51:33
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int size(Node* root){
        if(root == NULL) return 0;
        return 1 + size(root->left) + size(root->right);    
    }
    
    bool isMaxHeap(Node* root){
        if(root == NULL) return true;
        if(root->left != NULL && root->left->data > root->data) return false;
        if(root->right != NULL && root->right->data > root->data) return false;
        return isMaxHeap(root->left) && isMaxHeap(root->right);
    }
    
    bool isCST(Node* root,int idx,int& n){
        if(root == NULL) return true;
        if(idx > n) return false;
        return isCST(root->left,2*idx,n) && isCST(root->right, 2*idx+1, n);
    }
    
    bool isHeap(Node* root) {
        int n = size(root);
        return isMaxHeap(root) && isCST(root,1,n);
        
    }
};
```

*Generated on: 26/11/2026, 11:56:38 pm*