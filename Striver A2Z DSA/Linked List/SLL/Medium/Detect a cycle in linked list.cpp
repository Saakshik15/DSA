/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously 
following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
*/

/*

Approach 1 : Hashing

In this approach we will be using hasing and store the nodes(address and data) in the hash table. whenever there is a cycle in the linked list,
the nodes will be repeated, thus we can detect if there is a cycle in the linked list or not.
*/

//time complexity : O(N)
//space complexity : O(N)


/*
approach 2 : Fast and slow pointers

In this approach, we will be using two pointers, one is a fast pointer which moves two nodes per iteration
and the other one is a slow pointer which move one node per iteration.
Whenever there is a cycle in the linked list, the two pointers, fast and slow would be equal at a certain node.
If there is no cycle in the linked list, there will be a NULL pointer in the linked list, which will be encountered by fast pointer.
*/

//code :

bool detectLoop(Node* head)
    {
        // your code here
        Node* fast = head;
        Node* slow = head;

        while(fast != NULL && fast->next){
            fast= fast->next->next;
            slow= slow->next;
            if(fast == slow) return true;
        }
        return false;
    }

//time complexity : O(N)
//space complexity :O(1)
