# [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

## Note
 - Remember the elementary addition logic: carry
 - If we make a node everytime we meet list value, then it could have
   meaningless `0` which should be removed after whole iterations.

## Solutions

### Using two iterations

``` c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // init
    ListNode *acc = new ListNode(0);
    ListNode *result = acc;
    ListNode *prev = acc;

    int carry = 0;
    while (l1 != NULL && l2 != NULL) {
      acc->val = l1->val + l2->val + carry;
      if (acc->val >= 10) {
        carry = 1;
        acc->val -= 10;
      } else {
        carry = 0;
      }

      acc->next = new ListNode(0);

      l1 = l1->next;
      l2 = l2->next;
      prev = acc;
      acc = acc->next;
    }

    auto accum_one_list = [&](ListNode *l) {
      while (l != NULL) {
        acc->val = l->val + carry;
        if (acc->val >= 10) {
          carry = 1;
          acc->val -= 10;
        } else {
          carry = 0;
        }

        acc->next = new ListNode(0);
        l = l->next;
        prev = acc;
        acc = acc->next;
      }
    };

    accum_one_list(l1);
    accum_one_list(l2);

    if (carry != 0) {
      acc->val += carry;
      carry = 0;
    }

    if (acc->val == 0) {
      delete acc;
      prev->next = NULL;
    }

    return result;
  }
};
```

### Using one iteration

``` c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // copy one
    ListNode *result = new ListNode(0);
    ListNode *iter = result, *prev = result;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
      int v1 = (l1 == NULL ? 0 : l1->val);
      int v2 = (l2 == NULL ? 0 : l2->val);

      int v = v1 + v2 + carry;
      carry = v / 10;

      iter->val = v % 10;
      iter->next = new ListNode(0);

      if (l1 != NULL)
        l1 = l1->next;
      if (l2 != NULL)
        l2 = l2->next;
      prev = iter;
      iter = iter->next;
    }

    if (carry != 0) {
      iter->val = carry;
    }

    if (iter->val == 0) {
      prev->next = NULL;
      delete iter;
    }

    return result;
  }
};
```
