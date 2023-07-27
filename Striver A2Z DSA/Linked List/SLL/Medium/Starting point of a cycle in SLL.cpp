/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
Note that pos is not passed as a parameter.
Do not modify the linked list.
*/

/*
Solution : 

Approach :

We will be using fast and slow pointers in order to detect if there is a cycle present in the linked list.
The fast pointer will move 2 nodes ahed per iteration and slow pointer will move 1 node ahed per iteration.
If there is no cycle in the linked list, fast pointer, at some point will encounter null pointer.
If there is presence of a cycle in a linked list, fast and slow pointers will meet, or will be equal.
When fast and slow pointers are equal, there is a cycle in the linked list.

To find the starting point of the cycle, we will use a third pointer entry.
The entry pointer will start iterating from the head node till it is equal to the slow pointer.
This approach is based on the intuition that the distance of the node where slow and fast pointers meet to the starting of the loop, 
is same as the distance of head node and the starting point of the cycle in a linked list.

Now, instead of using a different pointer, we can reuse the fast pointer as the entry pointer as there is no 
requirement of the fast pointer and only slow pointer is required.
Thus, when we encounter fast==slow, we will reset the position of fast as fast= head and now move fast 1 node per iteration
and slow too, 1 node per iteration. 
Note that here we are reusing the fast pointer as entry point and not as a fast pointer as in the initial case.
Now, this time as the distance between head and entry point of cycle = distance where fast and slow pointer met and entry point of cycle,
again when these two pointers will meet will be the entry point of the cycle loop.
*/

//code :

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {  //node where slow and fast pointers meet
        //reuse of fast as entry pointer
        fast = head;
        
        while (slow != fast) {    //finding loop entry point
          slow = slow->next;
          fast = fast->next;
        }
        return fast;  //return fast or slow as both are equal and we have encountered entry point
      }
    }
  //in case there is no loop, while loop will encounter null and will terminate resulting returning nullptr
    return nullptr;
  }

//time complexity : O(N)
//space complexity : O(1)

  
