/*
Problem Statement : Given a positive integer represented in the form of a singly linked list of digits. The length of the number is n.
Add 1 to the number, i.e., increment the given number by one.
The digits are stored such that the most significant digit is at the head of the liked list and the least significant digit is 
at the tail of the linked list.

Sample Input 1:
1 5 2
Sample Output 1:
1 5 3
*/


/*
Approach 1 : recursive approach

In this approach, we will use recursion to add 1 to the linked list. We can recursively reach the last node, 
add 1 to it and forward the carry to the previous node. 

The steps are as follows:
Node *addOne(Node *‘head’)
Remove the leading zeroes by deleting the starting nodes with data value 0.
Let “addOneHelper” be the recursive function that takes the head of the linked list and returns the carry 
value given by the head node after adding 1.
If the head is NULL, return 1.
Find the carry obtained from the next node by recursively calling the function for the next node of the head.
Store the sum of the carry obtained from the next node and the current node’s data in a variable ‘res.’
Store res%10 in the current node’s data.
Return res/10.
After adding carry up to the first node of the list, if the value of carry is still non-zero, append a new node with 
its value at the beginning of the resultant linked list.
Return the head of the resultant linked list.
*/

//code :

int addOneHelper(Node *head){
    // If linked list is empty, return carry.
    if (head == NULL) return 1;
  
    // Add carry obtained from next node to current node data.
    int res = head->data + addOneHelper(head->next);
    // Update data and return new carry(to add to the previous node).
    head->data = res % 10;
    return res / 10;
}

Node *addOne(Node *head){
    // Add 1 to linked list from end to beginning
    int carry = addOneHelper(head);

    // If there is carry after processing all nodes,add a new node at the beginning of the linked list.
    if (carry != 0){

        Node *newHead = new Node(0);
        newHead->data = carry;
        newHead->next = head;

        // Return the new head of the resultant list
        return newHead;
    }
    return head;
}

//time complexity : O(n)
//space complexity : O(n)

/*

Approach 2 : Iterative approach

The basic idea is to reverse the given list to make addition easier. 

We will maintain a variable ‘carry’ with an initial value ‘1’ as we have to add 1 to the given number.

Now we will traverse the list from the least significant digit, which is at the starting of the reversed list, 
and for each digit, we will add ‘carry’ to it.

The steps are as follows:
Node *addOne(Node *‘head’)
Remove the leading zeros from the list.
Reverse the given linked list.
Take a variable ‘carry’ (with initial value 1).
Traverse the reversed list from starting to the end and for each node, perform the following steps.
Store sum of ‘carry’ and current node’s data in a variable ‘sum’.
Store sum/10 in ‘carry’. (For e.g., If the sum is 18, then 18/10 i.e. 1, will be the carry).
Store sum%10 to current node’s data.
If ‘carry’ is not zero
Add a new node at the end of the list with the data value ‘carry’.
Reverse the linked list to get the desired output.
*/

//code :

Node *reverse(Node *head) {
    // If the list is empty or has just one node, return head.
    if (head == NULL || head->next == NULL)  return head;
    // Pointer to the previous node of the current node.
    Node *prev = NULL;

    // Pointer to the current node.
    Node *curr = head;

    while (curr != NULL){
        // Pointer to the next node of the current node.
        Node *ahead = curr->next;

        // Inverting the links
        curr->next = prev;
        prev = curr;
        curr = ahead;
    }
    return prev;
}

Node *addOne(Node *head){
    // Reverse the list.
    head = reverse(head);
    Node *temp = head;
    // Initialize a variable to store carry.
    int carry = 1;
    // Initialize a pointer to store previous node.
    Node *prev = head;

    // Adding 1 to the reversed linked list
    while (head != NULL) {
        int sum = carry + head->data;
        carry = sum / 10;
        sum = sum % 10;
        head->data = sum;
        prev = head;
        head = head->next;
    }
    // If there is carry after processing all nodes, add a new node at the end of the linked list.
    if (carry != 0){
        Node *newNode = new Node(0);
        newNode->data = carry;

        // Appending the newNode at the end of the resultant list.
        if (prev != NULL) 
            prev->next = newNode;
        else{
            // If the resultant list is empty
            return newNode;
        }
    }
    // Reverse the resultant list.
    Node *ans = reverse(temp);
    return ans;
}

//time complexity : O(n)
//space complexity : O(1)

