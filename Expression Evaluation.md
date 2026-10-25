## 01. Expression Evaluation

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/fun-with-expresions2523/1)

### Problem Description

**Task:** You are given an array of strings arr[], that represents a valid infix expression. The task is to evaluate this expression.An infix expression is of the form "operand1 operator operand2" (e.g., "a + b"), where the operator is written between the two operands.

> **Note:** Infix expressions follow precedence: ^ (highest, right-to-left), then * and /, and finally + and - (left-to-right).The division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.

#### Examples

##### Example 1

- **Input:**
```text
arr[] = ["100", "+", "200", "/", "2", "*", "5", "+", "7"]
```
- **Output:**
```text
607Explanation: The expression can be directly read as: (100 + 200 / 2 * 5 + 7). Now, evaluate step by step: 200 / 2 = 100 100 * 5 = 500 500 + 100 = 600 600 + 7 = 607 Final Answer: 607
```

##### Example 2

- **Input:**
```text
arr[] = ["2", "^", "3", "^", "2"]
```
- **Output:**
```text
512Explanation: ^ is right-associative → 2 ^ (3 ^ 2) = 2 ^ 9 = 512. Final Answer: 512
```

#### Constraints

- **1.** `3 ≤ arr.size() ≤ 10⁵arr[i] is either an operator: "+", "-", "*", "/" or "^", or an integer in the range [1, 10⁴]`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-25 22:21:31
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int priority(string& s){
        if(s == "+" || s == "-") return 1;
        else if (s == "*" || s == "/") return 2;
        else return 3;
    }
    
    int operation(int& a, int& b, string& s){
        if(s == "+") return a+b;
        else if (s == "-") return a-b;
        else if(s == "*") return a*b;
        else if(s == "^") return pow(a,b);
        else return floor(double(a)/b);
    }
    int evaluateInfix(vector<string>& arr) {
        // code here
        stack<string> operators;
        stack<int> nums;
        for(string s : arr){
            if(s == "+" || s == "-" || s == "*" || s == "/" || s == "^"){
                if(s=="^") operators.push(s);
                else{
                    while(operators.size() > 0 && priority(operators.top()) >= priority(s)){
                        string op = operators.top();  operators.pop();
                        int b = nums.top(); nums.pop();
                        int a = nums.top(); nums.pop();
                        nums.push(operation(a,b,op));
                    }
                    operators.push(s);
                }
            }
            else nums.push(stoi(s));
        }
        while(operators.size() > 0){
            string op = operators.top(); operators.pop();
            int b = nums.top(); nums.pop();
            int a = nums.top(); nums.pop();
            nums.push(operation(a,b,op));
        }
        return nums.top();
    }
};
```

*Generated on: 25/10/2026, 10:21:53 pm*