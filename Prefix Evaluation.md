## 01. Prefix Evaluation

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/prefix-evaluation/1)

### Problem Description

**Task:** You are given an array of strings arr[] representing a prefix expression. Your task is to evaluate the expression and return an integer representing its value.

> **Note:** A prefix expression is of the form "operator operand1 operand2" (e.g., + a b).And the division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.

#### Examples

##### Example 1

- **Input:**
```text
arr[] = ["+", "*", "/", "+", "100", "200", "2", "5", "7"]Output: 757Explanation: If the expression is converted into an infix expression, it will be ((100 + 200) / 2) * 5 + 7 = 150 * 5 + 7 = 757.
```

##### Example 2

- **Input:**
```text
arr[] = ["^", "+", "2", "3", "2"]Output: 25Explanation: If the expression is converted into an infix expression, it will be (2 + 3) ^ 2 = 25.
```

#### Constraints

- **1.** `3 ≤ arr.size() ≤ 10³^arr[i] is either an operator: "+", "-", "*", "/" or "^", or an integer in the range [-10⁴, 10⁴]`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-25 20:18:16
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int operation(int&a , int& b, string& s){
            if(s == "+") return a+b;
            else if(s == "-") return a-b;
            else if(s == "*")   return a*b;
            else if(s == "^")   return pow(a,b);
            else{
                return floor(float(a)/b);
            }
        }
    int evaluatePrefix(vector<string>& arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        for(int i=n-1;i>=0;i--){
            string s = arr[i];
            if(s =="+" || s =="-" || s =="*" || s =="/" || s =="^" ){
                int a = st.top(); 
                st.pop();
                int b = st.top(); 
                st.pop();
                st.push(operation(a,b,s));
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};
```

*Generated on: 25/10/2026, 8:18:45 pm*