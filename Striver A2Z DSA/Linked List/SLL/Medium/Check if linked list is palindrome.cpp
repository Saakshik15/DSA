/*
Problem statement : Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
*/

/*
solution :

approach 1 :

first, store all the elements of the linked list in an array 
check if the array is palindrome or not.
If it is a palindrome, return true or false otherwise.

time complexity : O(N) +O(N)
space complexity : O(N)

*/

/*
Approach 2 :

In this approach, we will check if the linked list is a palindrome or not in the following way:
1. Find the middle of the linked list by using fast and slow pointers.
2. Reverse the linked list from the middle to the end.
3. use two pointers - one for traversing the linked list from head to middle and another for traversing the linked list from middle to end(NULL)
4. Compare the values of the nodes while traversing, return false if they are not equal
  finally when all values are equal and the pointer which will traverse from middle to end will reach NULL, we can conclude that it is a palindrome.

Now, there are two cases :
One where the linked list is even, in this case we will reverse the linked list from mid and check all elements.
Second where the linked list has odd no of nodes, in this case we will not check the mid element.

Now, after checking the palindrome if it is reuqired to obtain the linked list again, we will reverse the linked list again.
*/

//code :

ListNode* reverseList(ListNode* head){
        ListNode* pre=NULL;
        ListNode* next=NULL;

        while(head!=NULL){
            next=head->next;
            head->next= pre;

            pre=head;
            head=next;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return true;

      //find middle of linked list
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }

      //reverse the right half
        slow->next= reverseList(slow->next);
      //move slow th the right half
        slow= slow->next;

      //check if the right half and left half are equal or not
        ListNode* dummyHead= head;
        while(slow!=NULL){
            if(dummyHead->val != slow->val) return false;
            dummyHead= dummyHead->next;
            slow= slow->next;
        }
        return true;
    }

//time complexity : O(N) ...calculating overall
//space complexity : O(1)





//Leetcode solution for better understanding 

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Steps to follow:
        // 1_) Find the middle element
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2_) if the no of nodes are odd then move slow to one point
        if(fast != NULL && fast->next == NULL){
            slow = slow->next;
        }
        //3_) Reverse the end half
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        while(slow != NULL && slow->next != NULL){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        if(slow != NULL){
            slow->next = prev;
        }
        //4_) Compare the start half and end half if found any inequality then return false otherwise return true.
        fast = head;
        while(slow && fast){
            if(slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;

    }
};
