## 01. BST to Special Max Heap

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/bst-to-max-heap/1)

### Problem Description

**Task:** Given a Binary Search Tree, convert it into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

#### Examples

##### Example 1

- **Input:**
```text
root[] = [4, 2, 6, 1, 3, 5, 7]
```
- **Output:**
```text
[1, 2, 3, 4, 5, 6, 7]
```
- **Explanation:** The given BST has been transformed into a Special Max Heap while keeping the tree structure unchanged, and its postorder traversal is 1 2 3 4 5 6 7.The converted tree is:

##### Example 2

- **Input:**
```text
root[] = [5, 3, 8, 2, 4, 7, 9]
```
- **Output:**
```text
[2, 3, 4, 5, 7, 8, 9]
```
- **Explanation:** The given BST has been transformed into a Special Max Heap while keeping the tree structure unchanged, and its postorder traversal is 2 3 4 5 7 8 9. The converted tree is:

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-27 00:41:39
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
  
    void inorder(Node* root,vector<int>& ans){
        if(root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    
    void postorder(Node* root,vector<int>& ans, int& idx){
        if(root == NULL) return;
        postorder(root->left, ans,idx);
        postorder(root->right, ans,idx);
        root->data = ans[idx++];
        
    }
    void convertToMaxHeap(Node* root) {
        vector<int> ans;
        inorder(root,ans);
        int idx = 0;
        postorder(root,ans,idx);
    }
};
```

*Generated on: 27/11/2026, 12:41:21 am*