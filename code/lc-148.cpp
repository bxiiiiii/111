#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* sortList(ListNode* head) { return sortList(head, nullptr); }

  ListNode* sortList(ListNode* head, ListNode* tail) {
    if (head == nullptr) {
      return head;
    }
    if (head->next == tail) {
      head->next = nullptr;
      return head;
    }
    ListNode *slow = head, *fast = head;
    while (fast != tail) {
      slow = slow->next;
      fast = fast->next;
      if (fast != tail) {
        fast = fast->next;
      }
    }
    ListNode* mid = slow;
    return merge(sortList(head, mid), sortList(mid, tail));
  }

  ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* head = new ListNode(0);
    ListNode *temp = head, *temp1 = head1, *temp2 = head2;
    while (temp1 != nullptr && temp2 != nullptr) {
      if (temp1->val <= temp2->val) {
        temp->next = temp1;
        temp1 = temp1->next;
      } else {
        temp->next = temp2;
        temp2 = temp2->next;
      }
      temp = temp->next;
    }
    if (temp1 != nullptr) {
      temp->next = temp1;
    } else if (temp2 != nullptr) {
      temp->next = temp2;
    }
    return head->next;
  }
};

class Solution2 {
 public:
  ListNode* sortList(ListNode* head) {
    int size = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
      size++;
      temp = temp->next;
    }
    ListNode* re = new ListNode(0, head);
    for (int level = 1; level < size; level *= 2) {
      ListNode *pre = re, *cur = re->next;
      while (cur != nullptr) {
        ListNode* head1 = cur;
        for (int i = 1; i < level && cur->next != nullptr; i++) {
          cur = cur->next;
        }
        ListNode* head2 = cur->next;
        cur->next = nullptr;
        cur = head2;
        for (int i = 1; i < level && cur != nullptr && cur->next != nullptr;
             i++) {
          cur = cur->next;
        }
        ListNode* next = nullptr;
        if (cur != nullptr) {
          next = cur->next;
          cur->next = nullptr;
        }
        ListNode* merged = merge(head1, head2);
        pre->next = merged;
        while (pre->next != nullptr) {
          pre = pre->next;
        }
        cur = next;
      }
    }
    return re->next;
  }

  ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* re = new ListNode(0);
    ListNode *tem = re, *tem1 = head1, *tem2 = head2;
    while (tem1 != nullptr && tem2 != nullptr) {
      if (tem1->val <= tem2->val) {
        tem->next = tem1;
        tem1 = tem1->next;
      } else {
        tem->next = tem2;
        tem2 = tem2->next;
      }
      tem = tem->next;
    }
    if (tem1 != nullptr) {
      tem->next = tem1;
    } else if (tem2 != nullptr) {
      tem->next = tem2;
    }
    return tem->next;
  }
};

int main() {
  ListNode* head = new ListNode(4);
  ListNode* tem = new ListNode(2);
  ListNode* tem1 = new ListNode(1);
  ListNode* tem2 = new ListNode(3);
  head->next = tem;
  tem->next = tem1;
  tem1->next = tem2;
  tem2->next = nullptr;
  Solution2 s;
  auto re = s.sortList(head);
  return 0;
}