## 01. Infix To Prefix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1)

### Problem Description

**Task:** You are given a string s representing an infix expression. Convert this infix expression to a prefix expression.
Infix : The expression of the form a op b. When an operator is in between every pair of operands.
Prefix : The expression of the form op a b. When an operator comes before its two operands.
Precedence Order and Associativity are as follows:
^ has the highest precedence and is evaluated from right to left.
* and / come next with left to right associativity.
+ and - have the lowest precedence with left to right associativity.

#### Examples

##### Example 1

- **Input:**
```text
s = "a*(b+c)/d"Output: /*a+bcdExplanation: The infix expression is a*(b+c)/d. First, inside the brackets, b + c becomes +bc. Now the expression looks like a*(+bc)/d. Next, multiply a with (+bc), so it becomes *a+bc. Finally, divide this result by d, so it becomes /*a+bcd.
```

##### Example 2

- **Input:**
```text
s = "(a-b/c)*(a/k-l)"Output: *-a/bc-/aklExplanation: The infix expression is (a-b/c)*(a/k-l). First, inside the brackets, b/c becomes /bc and a/k becomes /ak.Now the expression looks like (a-/bc) * (/ak-l).Next, handle the subtractions: a-/bc becomes -a/bc, and /ak-l becomes -/akl. Finally, multiply the two results: (-a/bc * -/akl) becomes *-a/bc-/akl.
```

#### Constraints

- **1.** `3 ≤ s.length() ≤ 5*10³s[i] can be an operand (a–z, A–Z, 0–9), an operator (+, -, *, /, ^) or a parenthesis ((, ))`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-27 01:22:50
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
    string infixToPrefix(string &s) {
        // code here
        int n = s.size();
        stack<string> operand;
        stack<char>operators;

        for(int i=n-1;i>=0;i--){
            char ch = s[i];
            if(isalnum(ch))  operand.push(string(1,ch));
            else if(ch == ')') operators.push(ch);
            else if(ch == '('){
                while(!operators.empty() && operators.top() != ')'){
                    char op = operators.top(); operators.pop();
                    string a = operand.top(); operand.pop();
                    string b = operand.top(); operand.pop();
                    operand.push(string(1,op)+a+b);
                }
                if(!operators.empty()) operators.pop();
            }
            else{
                while (!operators.empty() && operators.top() != ')' &&
                (priority(operators.top()) > priority(ch) || (priority(operators.top()) == priority(ch)
                && ch  == '^'))){
                    char op = operators.top(); operators.pop();
                    string a = operand.top(); operand.pop();
                    string b = operand.top(); operand.pop();
                    operand.push(string(1,op)+a+b);          
                }
                operators.push(ch);
            }
        }
        while(!operators.empty()){
            char op = operators.top(); operators.pop();
            string a = operand.top(); operand.pop();
            string b = operand.top(); operand.pop();
            operand.push(string(1,op)+a+b);
        }
        return operand.top();
    }
};
```

*Generated on: 27/10/2026, 1:23:14 am*