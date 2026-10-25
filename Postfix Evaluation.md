## 01. Postfix Evaluation

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1)

### Problem Description

**Task:** You are given an array of strings arr[] that represents a valid arithmetic expression written in Postfix Notation. Your task is to evaluate the expression and return an integer representing its value.
The division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.
It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.
arr[i] is either an operator: "+", "-", "*", "/" or "^", or an integer in the range [-10⁴, 10⁴]

#### Examples

##### Example 1

- **Input:**
```text
arr[] = ["2", "3", "1", "*", "+", "9", "-"]
```
- **Output:**
```text
-4
```
- **Explanation:** If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.

##### Example 2

- **Input:**
```text
arr[] = ["2", "3", "^", "10", "+"]
```
- **Output:**
```text
18
```
- **Explanation:** If the expression is converted into an infix expression, it will be 2 ^ 3 + 10 = 8 + 10 = 18.

#### Constraints

- **1.** `3 ≤ arr.size() ≤ 10³`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-25 20:08:01
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
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        for(string s : arr){
            if(s =="+" || s =="-" || s =="*" || s =="/" || s =="^"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(operation(a,b,s));
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
```

*Generated on: 25/10/2026, 8:08:29 pm*