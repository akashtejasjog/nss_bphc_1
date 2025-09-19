/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry_digit = 0;
        int keep_digit = 0;
        int x, y, sum;
        ListNode out_list;
        ListNode *out_ptr = &out_list;
        while ((l1 != nullptr) or (l2 != nullptr))
        {
            x = (l1 != nullptr) ? l1->val : 0;
            y = (l2 != nullptr) ? l2->val : 0;
            sum = x + y + carry_digit;
            keep_digit = (sum) % 10;
            carry_digit = (int)((sum) / 10);
            l1 = (l1) ? l1->next : l1;
            l2 = (l2) ? l2->next : l2;
            out_ptr->next = new ListNode(keep_digit);
            out_ptr = out_ptr->next;
        }
        if (carry_digit > 0)
        {
            out_ptr->next = new ListNode(carry_digit);
        }
        return out_list.next;
    }
};