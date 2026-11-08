## 01. Left View of Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1)

### Problem Description

**Task:** Given the root of a binary tree. Return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

> **Note:** If the tree is empty, return an empty list.

#### Examples

##### Example 1

- **Input:**
```text
root = [1, 2, 3, 4, 5, N, N] Output:[1, 2, 4]Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.
```

##### Example 2

- **Input:**
```text
root = [1, 2, 3, N, N, 4, N, N, 5, N, N]
```
- **Output:**
```text
[1, 2, 4, 5]Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (2)

#### Solution 1 (C++)

- **Submitted:** 2026-11-08 20:31:54
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
        // Method -2
    void preorder(Node* root, vector<int>& ans, int level){
        if(root == NULL) return;
        if(level == ans.size())
            ans.push_back(root->data);
        preorder(root->left,ans,level+1);
        preorder(root->right,ans,level+1);
    }
    
    vector<int> leftView(Node *root) {
       vector<int> ans;
       preorder(root,ans,0);
       return ans;
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-11-08 20:26:45
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    int levels(Node* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left) , levels(root->right));
    }

    void preorder(Node* root, vector<int>& ans, int level){
        if(root == NULL) return;
        if(ans[level] == -1)
            ans[level] = root->data;
        preorder(root->left,ans,level+1);
        preorder(root->right,ans,level+1);
    }
    
    vector<int> leftView(Node *root) {
       int n = levels(root);
       vector<int> ans(n,-1);
       preorder(root,ans,0);
       return ans;
    }
};
```

*Generated on: 8/11/2026, 8:32:13 pm*