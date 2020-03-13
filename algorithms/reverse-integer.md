# [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/)

## Note
 - We can optimize by hoisting some constant calculations. In this
   case, the positive check and cap value.

## Solution

### Optimized

``` c++
class Solution {
public:
  int reverse(int x) {
    int answer = 0;

    // Hoist cap & positivity
    bool is_positive = x > 0;
    int cap = is_positive ? INT_MAX / 10 : INT_MIN / 10;

    while (x != 0) {
      int v = x % 10;
      x /= 10;

      if (is_positive && answer > cap)
        return 0;
      if (!is_positive && answer < cap)
        return 0;

      answer = answer * 10 + v;
    }

    return answer;
  }
};
```

### First try

``` c++
class Solution {
public:
  int reverse(int x) {
    int answer = 0;

    while (x != 0) {
      int v = x % 10;
      x /= 10;

      if (answer > INT_MAX / 10)
        return 0;
      if (answer < INT_MIN / 10)
        return 0;
      answer = answer * 10 + v;
    }

    return answer;
  }
};
```
