## 01. Infix to Postfix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1)

### Problem Description

**Task:** You are given a string s representing an infix expression. Convert this infix expression to a postfix expression.
Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.

> **Note:** The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left, (* and /) come next with left to right associativity, and (+ and -) have the lowest precedence with left to right associativity.

#### Examples

##### Example 1

- **Input:**
```text
s = "a*(b+c)/d"
```
- **Output:**
```text
abc+*d/
```
- **Explanation:** The expression is a*(b+c)/d. First, inside the brackets, b+c becomes bc+. Now the expression looks like a*(bc+)/d. Next, multiply a with (bc+), so it becomes abc+* . Finally, divide this result by d, so it becomes abc+*d/.

##### Example 2

- **Input:**
```text
s = "a+b*c+d"
```
- **Output:**
```text
abc*+d+
```
- **Explanation:** The expression a+b*c+d is converted by first doing b*c - > bc*, then adding a - > abc*+, and finally adding d - > abc*+d+.

##### Example 3

- **Input:**
```text
s = "(a+b)*(c+d)"
```
- **Output:**
```text
ab+cd+*Explanation: The expression (a+b)*(c+d) is converted by first doing (a+b) - > ab+, then doing (c+d) - > cd+, and finally the expression ab+*cd+ becomes ab+cd+*.
```

#### Constraints

- **1.** `1 ≤ s.length ≤ 5*10³s[i] can be an operand (a–z, A–Z, 0–9), an operator (+, -, *, /, ^) or a parenthesis ((, ))`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-27 00:59:56
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int priority(char& ch){
        if(ch == '+' || ch == '-') return 1;
        else if(ch == '*' || ch == '/') return 2;
        else return 3;
    }
    string infixToPostfix(string& s) {
        // code here
        stack<string> operand;
        stack<char>operators;
        
        for(char ch : s){
            if(isalnum(ch))  operand.push(string(1,ch));
            else if(ch == '(') operators.push(ch);
            else if(ch == ')'){
                while(!operators.empty() && operators.top() != '('){
                    char op = operators.top(); operators.pop();
                    string b = operand.top(); operand.pop();
                    string a = operand.top(); operand.pop();
                    operand.push(a+b+op);
                }
                if(!operators.empty()) operators.pop();
            }
            else{
                while (!operators.empty() && operators.top() != '(' &&
                (priority(operators.top()) >= priority(ch)  && ch != '^')){
                    char op = operators.top(); operators.pop();
                    string b = operand.top(); operand.pop();
                    string a = operand.top(); operand.pop();
                    operand.push(a+b+op);          
                }
                operators.push(ch);
            }
        }
        while(!operators.empty()){
            char op = operators.top(); operators.pop();
            string b = operand.top(); operand.pop();
            string a = operand.top(); operand.pop();
            operand.push(a+b+op);
        }
        return operand.top();
    }
};
```

*Generated on: 27/10/2026, 1:00:37 am*