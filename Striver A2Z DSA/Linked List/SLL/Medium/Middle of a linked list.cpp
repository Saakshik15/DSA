/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
*/

/*
solution :

approach 1 : brute force approach

to find the middle of the linked list, we will first iterate throgh all the elements of the linked list and keep
a count of the number of elements in the linked list.
Then, we will divide the count by 2. 
Then, again iterting through the linked list till the count variable becomes zero, we will return the node at which counter variable points.
*/

// code :

ListNode* middleNode(ListNode* head) {
        struct ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int middle = count / 2;

        struct ListNode* middleNode = head;
        int iterate = 0;
        while (iterate != middle) {
            middleNode = middleNode->next;
            iterate++;
        }
    return middleNode;
    }

//time complexity : O(N) + O(N/2)
//space complexity : O(1)

/*
approach 2 : tortoise and hare

we will traverse the linked list using two pointers,
one is the fast pointer which moves 2 nodes in each iteration 
and the other is slow pointer which moves only one node in each iteration.

since the fast pointer will move 2 iterations, when it reaches end of the linked list, 
the slow would have reached the middle of the linked list
hence, we will return the node pointed by the slow pointer
*/

//code :

Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast!= NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }

//time complexity : O(N/2)
//space complexity : O(1)
