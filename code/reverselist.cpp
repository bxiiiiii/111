//   Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode* q = nullptr;
    ListNode* p = head->next;
    for (; p != nullptr;) {
      head->next = q;
      q = head;
      head = p;
      p = head->next;
    }
    head->next = q;
    q = head;
    return head;
  }
};