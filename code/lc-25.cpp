#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *q = head;
    ListNode *pre = nullptr;
    for (int num = 0; q != nullptr; num++) {
      vector<ListNode *> vec;
      ListNode *p = q;
      vec.push_back(p);
      for (int i = k; i > 1; i--) {
        p = p->next;
        vec.push_back(p);
        if (p == nullptr) {
          return head;
        }
      }

      if (pre != nullptr) {
        pre->next = vec[vec.size() - 1];
      }
      vec[0]->next = vec[vec.size() - 1]->next;
      for (int i = vec.size() - 1; i > 0; i--) {
        vec[i]->next = vec[i - 1];
      }

      if (num == 0) {
        head = p;
      }
      pre = q;
      q = q->next;
    }

    return head;
  }
};