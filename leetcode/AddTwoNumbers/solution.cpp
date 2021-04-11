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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        int carry = 0;
        int sum;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* h3 = nullptr;
        ListNode* n = nullptr;
        while(h1 && h2){
            sum = h1->val + h2->val + carry;
            carry = sum/10;
            sum = sum % 10;
            
            if (h3 == nullptr){
                h3 = new ListNode(sum);
                n= h3;
            }
            else{
                ListNode* temp = new ListNode(sum);
                n->next = temp;
                n = temp;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        while(h1){
            sum = h1->val + carry;
            carry = sum/10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            n->next = temp;
            n = temp;
            h1 = h1->next;
        }
        while(h2){
            sum = h2->val + carry;
            carry = sum/10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            n->next = temp;
            n = temp;
            h2 = h2->next;
        }
        if (carry == 1){
            ListNode* temp = new ListNode(1);
            n->next = temp;
        }
        return h3;
    }
};
