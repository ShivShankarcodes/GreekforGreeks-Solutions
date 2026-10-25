## 01. Prefix to Infix Conversion

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1)

### Problem Description

**Task:** Given a string s representing a valid mathematical expression in prefix notation. The string consists of uppercase and lowercase English letters as operands, and the operators +, -, *, /, %, and ^.
Convert the given prefix expression into its equivalent fully parenthesized infix expression and return the resulting string.

#### Examples

##### Example 1

- **Input:**
```text
s = "*-A/BC-/AKL"
```
- **Output:**
```text
((A-(B/C))*((A/K)-L))
```
- **Explanation:** The prefix expression starts with '*', so the final operation is multiplication.The left subexpression '-A/BC' converts to '(A-(B/C))', and the right subexpression '-/AKL' converts to '((A/K)-L)'. Combining these two subexpressions with '*' gives the fully parenthesized infix expression: ((A-(B/C))*((A/K)-L))

##### Example 2

- **Input:**
```text
s = "+A*BC"Output: (A+(B*C))Explanation: The prefix expression starts with '+', so the final operation is addition. The left operand is 'A', and the right subexpression '*BC' converts to '(B*C)'. Combining them with '+' gives the fully parenthesized infix expression: (A+(B*C))
```

#### Constraints

- **1.** `3 ≤ |S| ≤ 10⁵`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-25 20:48:21
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    string preToInfix(string &s) {
        // code here
        int n = s.size();
        stack<string> st;
        for(int i=n-1;i>=0;i--){
            char ch = s[i];
            if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^'){
                string a = st.top();    st.pop();
                string b = st.top();    st.pop();
                st.push("(" + a + string(1,ch) + b + ")");
            }
            else{
                st.push(string(1,ch));
            }
        }
        return st.top();
    }
};
```

*Generated on: 25/10/2026, 8:48:46 pm*