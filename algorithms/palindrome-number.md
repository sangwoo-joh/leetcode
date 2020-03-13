# [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/)

## Note
 - Filter out negative fast.
 - Compare the input with its reversed value.
 - Input could be 2,147,483,647, which is the maximum of `int`, so its
   reversed value could be overflow for `int`. So, use `long long`.

## Solution

``` c++
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int copy = x;
        long long reversed = 0;

        while (copy != 0) {
            reversed = reversed * 10 + copy % 10;
            copy /= 10;

        }

        return x == reversed;
    }
};
```
