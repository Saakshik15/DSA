/*
Problem statement: Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

/*
Solution: 

approach 1 :

Count the number of nodes traversing the whole linked list.
Subtract the given number of node from total number of nodes.
Delete the resulted node number.

  Time complexity : O(2N) in worst case
  Space complexity : O(1)
*/

/*
Approach 2 :

Have a dummy node start, whose next pointer shall point to the head node.
Have two more pointers fast and slow which are at the start pointer.
Move the fast pointer ahed given number of nodes times.
Now, when fast has moved n nodes, move slow from the dummy node 1 node forward per iteration till the fast pointer reaches the last node
(i.e., fast->next = NULL) moving both pointers one node per iteration.
Now, the slow pointer's position will by default be at the node previous to the node to be deleted.
Dereference the start's next and point it to start's next's next, in this way there will be no links to the node to be deleted.
(i.e., start->next= start->next->next)
Edge case : In case the node to be deleted is the head itself, we have a dummy start pointer, which will point to the
the slow's next will be head at initial and later it will become slow's next's next which is the second node.
        slow->next= slow->next->next;
Thus, we will return start's next in each case since it is always pointed to head. 
*/

//code :

ListNode* removeNthFromEnd(ListNode* head, int n) {

  //dummy node start which is before head
        ListNode* start= new ListNode();
        start->next= head;

  //initially, both pointers before head, at the dummy node's position
        ListNode* fast= start;
        ListNode* slow= start;

  //will move fast pointer till it iterates n nodes (nodes to be deleted)
        while(n--){
            fast= fast->next;
        }

  //now, we will move slow pointer till fast reaches the last node, thus, start will be pointing to node before the to be deleted node
  //in case the to be deleted node is head(n=no of nodes), fast->next will be NULL and this loop will not be executed
  //in that case, start & slow both will be pointing before the head node
        while(fast->next!=NULL){
            slow= slow->next;
            fast = fast->next;
        }
  //deleting the node after start by dereferencing the pointers
  //in case the node to be deleted is head, slow is at the dummy node before head, and it will now point to the node after head
        slow->next= slow->next->next;

  //returning start->next in case the head is not deleted, start is before the head node
  //in case head was deleted, the slow pointer has already dereferenced the head and now the head is next node of the prev node of head
        return start->next;
    }

// code : (without comments)

ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* start= new ListNode();
        start->next= head;
        ListNode* fast= start;
        ListNode* slow= start;

        while(n--){
            fast= fast->next;
        }
        while(fast->next!=NULL){
            slow= slow->next;
            fast = fast->next;
        }
        slow->next= slow->next->next;       
        return start->next;
    }

//time complexity : O(N)
//space complexity : O(1)
