#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) {
      return false;
    }
    ListNode *slow = head, *fast = head;
    do {
      slow = slow->next;
      fast = fast->next;
      if (slow == nullptr || fast == nullptr) {
        return false;
      }
      if (fast->next == nullptr) {
        return false;
      } else {
        fast = fast->next;
      }
    } while (slow != fast);
    return true;
  }
};