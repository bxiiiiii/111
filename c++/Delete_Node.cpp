//237.Delete NOde in a Linked List
/*Write a function to delete a node in a singly-linked list.You will not be 
given access to the head of the list,instead you will given access to the node
 to be deleted directly*/

 /*
  Definition for singly-linked list.
 */ 
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
     };
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tem = node->next;
        node->val = tem->val;
        node->next = tem->next;
        
        delete tem;
    }
};

