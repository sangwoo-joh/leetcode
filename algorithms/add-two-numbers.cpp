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
