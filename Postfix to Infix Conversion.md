## 01. Postfix to Infix Conversion

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1)

### Problem Description

**Task:** Given a string s that represents the postfix form of a valid mathematical expression. Convert it to its infix form.Example:Input: s = "ab*c+"

#### Examples

##### Example 1

- **Output:**
```text
((a*b)+c)
```
- **Explanation:** The postfix expression ab*c+ represents (a*b)+c. Therefore, its equivalent infix expression is ((a*b)+c).

##### Example 2

- **Input:**
```text
s = "abc/-"
```
- **Output:**
```text
(a-(b/c))
```
- **Explanation:** The postfix expression abc/- represents a-(b/c). Therefore, its equivalent infix expression is (a-(b/c)).

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-25 20:26:48
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    string postToInfix(string &s) {
        // code here
        stack<string> st;
        for(char ch : s){
            if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%'){
                string b = st.top(); st.pop();
                string a = st.top(); st.pop();
                st.push("(" + a + string(1,ch) + b + ")");
            }
            else {
                st.push(string(1,ch));
            }
        }
        return st.top();
    }
};
```

*Generated on: 25/10/2026, 8:29:59 pm*