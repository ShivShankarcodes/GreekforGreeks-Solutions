## 01. Palindrome Sentence

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1)

### Problem Description

**Task:** Given a single string s, the task is to check if it is a palindrome sentence or not.A palindrome sentence is a sequence of characters, such as word, phrase, or series of symbols that reads the same backward as forward after converting all uppercase letters to lowercase and removing all non-alphanumeric characters (including spaces and punctuation).

#### Examples

##### Example 1

- **Input:**
```text
s = "Too hot to hoot"
```
- **Output:**
```text
true
```
- **Explanation:** If we remove all non-alphanumeric characters and convert all uppercase letters to lowercase, string s will become "toohottohoot" which is a palindrome.

##### Example 2

- **Input:**
```text
s = "Abc 012..## 10cbA"
```
- **Output:**
```text
true
```
- **Explanation:** If we remove all non-alphanumeric characters and convert all uppercase letters to lowercase, string s will become "abc01210cba" which is a palindrome.

##### Example 3

- **Input:**
```text
s = "ABC $. def01ASDF"Output: falseExplanation: The processed string becomes "abcdef01asdf", which is not a palindrome.
```

#### Constraints

- **1.** `1 ≤ s.length() ≤ 10⁶`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (2)

#### Solution 1 (C++)

- **Submitted:** 2026-10-27 22:48:43
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int n = s.size();
        int i=0 , j=n-1;
        while(i<j){
            while(i<j && !isalnum(s[i])) i++;
            while(i<j && !isalnum(s[j])) j--;
            
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-10-27 22:43:00
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    bool notValid(char& ch){
        if(ch >= 65 && ch <= 90) return false;
        else if(ch >= 97 && ch <= 122) return false;
        else if(ch >= 48 && ch <= 57) return false;
        else return true;
    }
    bool isPalinSent(string &s) {
        // code here
        int n = s.size();
        int i=0 , j=n-1;
        while(i < j){
            char x = s[i] , y = s[j];
            if(x >= 65 && x <= 90) x+=32; // convert capital letter into small
            if(y >= 65 && y <= 90) y+=32; // convert capital letter into small
            if(notValid(x)) i++;
            else if(notValid(y)) j--;
            else{
                if(x != y) return false;
                i++;
                j--;
            }
        }
        return true;
    }
};
```

*Generated on: 27/10/2026, 10:49:07 pm*