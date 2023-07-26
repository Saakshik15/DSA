/*
Problem statement : Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

//approach : reversing the pointers (iterative approach)

//code : (Iterative approach)

ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;

        while(head != NULL){
            ListNode* temp = head->next;
            head->next = newHead;

            newHead = head;
            head= temp;
        }
        return newHead;
    }

//time complexity : O(N)
//space complexity : O(1)
