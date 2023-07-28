/*
Given the head of a linked list, delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, 
where ⌊x⌋ denotes the largest integer less than or equal to x.
For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
*/

/*
Approach :

Find the middle of the linked list by fast and slow pointers.
Maintain a pointer prev before the slow pointer.
As slow reaches middle of the linked list, dereference, prev->next = prev->next->next.
finally, delete slow.
edge case where slow is head, i.e., list has only one element, make head as nullptr and return it.
Return head.
*/

//code :

ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev;

        while (fast && fast->next) {    //find middle of the linked list
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow != head)         
            prev->next = prev->next->next;     //the pointers are: prev-> slow-> (slow->next or prev->next->next)
        else 
            head = nullptr;      //edge case where no of nodes is 1, se delete head by making it null

        slow->next = nullptr;   //dereferencing slow->next as null before deleting
        delete slow;
        
        return head;
    }

//time complexity : O(N)
//space complexity : O(1)
