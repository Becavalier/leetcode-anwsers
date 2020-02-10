#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* cursor = head;
    bool hasCarry = false;
    do {
      int sum = 0;
      // plus the carry;
      if (hasCarry) {
        sum += 1;
        hasCarry = false;
      }
      // plus the number in each list;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      // determine the next carry;
      if (sum > 9) { hasCarry = true; }
      // set proper value;
      cursor->next = new ListNode(0);
      cursor->val = sum % 10;
      // deal with the condition in the last loop;
      if (l1 == nullptr && l2 == nullptr) {
        // don't forget the last carry;
        /**
         * [2, 4, 5]
         * [5, 6, 5]
         *  |  |  |
         * [7, 0, 1, 1]
         */
        if (hasCarry) {
          cursor->next->val = 1; 
        } else {
          // remove the last temp node (created in the circular loop);
          cursor->next = nullptr;
        }
      } else {
        cursor = cursor->next;
      }
    } while (l1 != nullptr || l2 != nullptr);
    return head;
  }
};
