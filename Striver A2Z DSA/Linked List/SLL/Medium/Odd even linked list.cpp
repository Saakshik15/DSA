/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, 
and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.
*/

/*
Solution : 

approach 1 : brute force approach

In this approach, we will use two pointers, odd and even and will traverse the list.
We will create two extra pointers as NULL which will be the linked lists even and odd
now, whenever we have odd index, we will add that node to the linked list for odd indices.
Whenever we have an even node, we will add that node to the linked list for even indices.
The end of both the lists will be NULL.
Now, in order to form the linked list where all even index elements are after odd,
simply make the last null pointer of add list point to the head of even list
*/

/*
Approach 2 : 

The head is at index 1, so initialize it as odd
The even index thus will be the 2nd index, which is head->next.
We will maintain another pointer as evenHead= even coz we will lose the even head while iterating and it is useful to merge the lists at the end.
We will continue iterating till the even reaches NULL or even's next(in case of even number of elements) is NULL
Now, we will change the pointers, as :
for odd,
odd->next= odd->next->next;
odd= odd->next; (since we've changed pointers)
for even,
even->next= even->next->next;
even= even->next;
finally, we have changed the pointers, it's time to merge these two lists by assigning odd->next = evenHead (which we had stored previously)

*/


//code : 

ListNode* oddEvenList(ListNode* head) {
    if(head==NULL) return head;

    ListNode* odd= head;
    ListNode* even= head->next;

    //Maintain the even head coz we are traversing the even pointer
    ListNode* evenHead= even;

    while(even!=NULL && even->next!= NULL){

        //change pointers for odd list
        odd->next= odd->next->next;
        odd= odd->next;

        //change pointers for even list
        even->next= even->next->next;
        even= even->next;
    }
    //Assign even list at the end of the odd list
    odd->next= evenHead;

    return head;
}

//time complexity : O(N)
//space complexity : O(1)
