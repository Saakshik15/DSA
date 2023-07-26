/*
Problem statement : Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

//approach 1 : reversing the pointers (iterative approach)

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

/*
Approach 2 : recursive approach 

We traverse to the end of the list recursively.
As we reach the end of the list, we make the end node the head. Then receive previous nodes and make them connected to the last one.
At last, we link the second node to the head and the first node to NULL. We return to our new head.
*/

//code :

ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h2;
    }

//time complexity : O(N)
//space complexity : O(1)
