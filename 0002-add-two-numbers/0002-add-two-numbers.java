/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 /** 
 Time Complexity = O(n)
 Space Complexity = O(n) (if the sum hava n digits, we create n new objects)
 */ 

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        //creating dummyHead to avoid "dirty code" and reach a cleaner code
        ListNode dummyHead = new ListNode();
        ListNode current = dummyHead;
        int rest = 0;

        while (l1!=null||l2!=null||rest!=0){
            //if they don't have a value, we consider them as zeros
            int x = (l1!=null)? l1.val : 0;
            int y = (l2!=null)? l2.val : 0;

            int sum = rest + x + y;
            rest = sum/10;
            //assigning new value
            current.next = new ListNode(sum%10);
            //go to next val
            current = current.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
            }
    return dummyHead.next;
        }
    }