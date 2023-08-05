/*
Problem Statement : Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
*/

/*
Solution : 
  
Approach 1 : Brute force

Keep any one of the list to check its node present in the other list.
Iterate through the other list.
Check if the both nodes are the same. If yes, we got our first intersection node. If not, continue iteration.
If we did not find an intersection node and completed the entire iteration of the second list, 
then there is no intersection between the provided lists. Hence, return null.
*/

//code :

node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}

//Time Complexity: O(m*n) bcz as for each node in list 2 entire lists 1 are iterated. 
//Space Complexity: O(1) No extra space is used.


/*
Approach 2 : better solution using hashing

Iterate through list 1 and hash its node address.
Iterate through list 2 and search the hashed value in the hash table. If found, return node.
*/


//code : 

node* intersectionPresent(node* head1,node* head2) {
     unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}

//Time Complexity: O(n+m)
//Space Complexity: O(n)

/*
Approach 3 : optimal approach 1 using Difference in length

Find the length of both lists.
Find the positive difference between these lengths.
Move the dummy pointer of the larger list by the difference achieved. This makes our search length reduced to a smaller list length.
Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.
*/

//code : 

node* intersectionPresent(node* head1,node* head2) {
 int diff = getDifference(head1,head2);
        if(diff < 0) 
            while(diff++ != 0) head2 = head2->next; 
        else while(diff-- != 0) head1 = head1->next;
        while(head1 != NULL) {
            if(head1 == head2) return head1;
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1;
}

//time complexity : O(2max(len1,len2))  +  O(abs(len1-len2))  +  O(min(len1,len2))
//space complexity : O(1)

/*
Approach 4: optimized approach using length diff

The difference of length method requires various steps to work on it. Using the same concept of difference of length, 
a different approach can be implemented. The process is as follows:-
Take two dummy nodes for each list. Point each to the head of the lists.
Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.
*/

//code :

node* intersectionPresent(node* head1,node* head2) {
    node* d1 = head1;
    node* d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    return d1;
}

//time complexity : O(2* max(len1,len2))
//space complexity : O(1)
