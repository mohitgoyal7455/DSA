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
    ListNode* getkthnode(ListNode* head, int k=2) {
        ListNode* temp = head;
        int count = 1;

        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* kth = getkthnode(temp, 2);

            if (kth == NULL) {
                if (prev != NULL)
                    prev->next = temp;
                break;
            }

            ListNode* next = kth->next;
            kth->next = NULL;

            ListNode* reversedHead = reverse(temp);

            if (temp == head)
                head = reversedHead;
            else
                prev->next = reversedHead;

            prev = temp;
            temp = next;
        }
        return head;
    } 
        
    
};