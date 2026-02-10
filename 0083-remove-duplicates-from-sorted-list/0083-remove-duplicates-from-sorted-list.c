/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /* 
 implementing algorithm to remove duplicate numbers from sorted list
 O(n) time complexity (while loop)
 O(1) space complexity
  */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    //Edge case
    if (head==NULL || head->next == NULL) return head;
    struct ListNode* current = head;
    //the only loop in the algorithm, need this to verify all the numbers till the end of the list
    while (current->next!= NULL){
        //if the next value same as the current, skip to the next
        if (current->val==current->next->val){
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
            }else {
                current = current->next;
            }
    }
    return head;
}